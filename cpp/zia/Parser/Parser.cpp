#include "Error.hpp"
#include "Parser.h"

typedef void	(parser::*methodPtr)();

struct				lexerSymbol 
{
	const char*		str;
	unsigned int	size;
	parser::symbol	sym;
};

lexerSymbol	lex[] =
{
	{"\r\n", 2, parser::TS_CRLF},
	{"\n", 1, parser::TS_LF},
	{"\r", 1, parser::TS_CR},
	{":", 1, parser::TS_COLON},
	{" ", 1, parser::TS_SP},
	{" ", 1, parser::TS_HT},
	{"\0", 1, parser::TS_EOF},
	{"", 0, parser::TS_OTHER}
};

struct				method
{
	const char*		str;
	unsigned int	size;
};

method		meth[] =
{
	{"HEAD", 4},
	{"GET", 3},
	{"POST", 4},
	{"PUT", 3},
	{"DELETE", 6},
	{"TRACE", 5},
	{"OPTIONS", 7},
	{"CONNECT", 7},
	{"PATCH", 5},
	{"", 0}
};

parser::parser()
{
	this->_index = 0;
	this->_nbParseMethod = 14;
	this->_table[NTS_HEADER][TS_OTHER] = HEADER;
	this->_table[NTS_HEADERS][TS_CRLF] = HEADERS;
	this->_table[NTS_HEADERS][TS_EOF] = EPSILON;
	this->_table[NTS_HTTPTOKEN][TS_OTHER] = HTTPTOKEN;
	this->_table[NTS_VALUE][TS_OTHER] = VALUE;
	this->_table[NTS_VALUES][TS_EOF] = EPSILON;
	this->_table[NTS_VALUE][TS_EOF] = EPSILON;
	this->_table[NTS_VALUES][TS_SP] = VALUESLWS;
	this->_table[NTS_VALUES][TS_HT] = VALUESLWS;
	this->_table[NTS_VALUES][TS_LWS] = VALUESLWS;
	this->_table[NTS_VALUES][TS_CRLF] = EPSILON;
	this->_table[NTS_VALUES][TS_OTHER] = VALUESVALUE;
	this->_table[NTS_VALUES][TS_COLON] = VALUESVALUE;
	this->_table[NTS_LWS][TS_LWS] = LWS;
	this->_table[NTS_LWS][TS_SP] = LWS;
	this->_table[NTS_LWS][TS_HT] = LWS;
	this->_table[NTS_REQUEST][TS_OTHER] = REQUEST;
	this->_table[NTS_CMDLINE][TS_OTHER] = CMDLINE;
	this->_table[NTS_METHOD][TS_OTHER] = METHOD;
	this->_table[NTS_URL][TS_OTHER] = URL;
	this->_table[NTS_VERSION][TS_OTHER] = VERSION;
}


parser::symbol	parser::lexer()
{
	parser::symbol	res = TS_OTHER;

	for (int i = 0; lex[i].sym != TS_OTHER; ++i)
	{
		if (this->_requestString->compare(this->_index, lex[i].size, lex[i].str) == 0)
		{
			res = lex[i].sym;
			break;
		}
	}
	if (res == TS_CRLF && this->isLWS(this->_index) == true)
		res = TS_LWS;
	if (res == TS_OTHER && (*this->_requestString)[this->_index] == '\0')
		res = TS_EOF;
	return res;
}

void		parser::parse(std::string &strRequest, zia::api::DataTree& dT)
{
	methodPtr			tableMethodPtr[] = {&parser::defaulted, &parser::httpToken, &parser::value, &parser::header, &parser::valuesLws, &parser::valuesValue, &parser::epsilon, &parser::lws, &parser::headers, &parser::cmdLine, &parser::request, &parser::method, &parser::url, &parser::version};

	this->_requestString = &strRequest;
	this->_index = 0;

	// init stack
	while (this->_ss.empty() == false)
		this->_ss.pop();
	this->_ss.push(TS_EOF);
	this->_ss.push(NTS_REQUEST);

	while (this->_ss.size() > 0 && this->_index < this->_requestString->size())
	{
		if (lexer() == this->_ss.top())
		{
			if (this->_ss.top() == TS_CRLF)
				this->_index++;
			this->_index++;
			this->_ss.pop();
			// tree
		}
		else
		{
			if (this->_table[this->_ss.top()][lexer()] > this->_nbParseMethod)
				throw Error(PARSER_ERROR);
			else
			{
				(this->*tableMethodPtr[this->_table[this->_ss.top()][lexer()]])();
			}
		}
	}
	
	if (this->_ss.size() > 0 && this->_index >= this->_requestString->size())
	  throw Error(PARSER_ERROR);
	dT = this->_newrequest;
	this->_newrequest.clear();
}

void	parser::defaulted()
{
	throw Error(PARSER_ERROR);
}

bool	parser::isCTLs(char c) const //<tout caractère de contrôle US-ASCII (octets 0 - 31) et DEL (127)>
{
	if ((c <= 31 && c >= 0) || c == 127)
		return (true);
	return (false);
}

bool	parser::isSeparators(char c) const // "(" | ")" | "<" | ">" | "@" | "," | ";" | ":" | "\" | <"> | "/" | "[" | "]" | "?" | "=" | "{" | "}" | SP | HT
{
	std::string	separators = "()<>@,;:\"\\/[]?={} \t";

	if (separators.find_first_of(c) != std::string::npos)
		return (true);
	return (false);
}

bool	parser::isChar(char c) const // <tout caractère US-ASCII (octets 0 - 127)>
{
	return c >= 0;
}

bool	parser::isLWS(int i) const
{
	if (this->_requestString->compare(i, 2, "\r\n") == 0)
		i += 2;
	if ((*(this->_requestString))[i] == ' ' || (*(this->_requestString))[i] == '\t')
		return (true);
	return (false);
}

bool	parser::isNumber(char c) const
{
	if (c <= '9' && c >= '0')
		return (true);
	return (false);
}

void	parser::httpToken() //1*<any CHAR except CTLs ou separators>
{
	if (this->isChar((*(this->_requestString))[this->_index]) == false || this->isCTLs((*(this->_requestString))[this->_index]) == true || this->isSeparators((*(this->_requestString))[this->_index]) == true)
		throw Error(PARSER_ERROR);

	this->_actualKey = "";
	this->_ss.pop();
	while (this->_index < this->_requestString->length() && this->isChar((*(this->_requestString))[this->_index]) == true && this->isCTLs((*(this->_requestString))[this->_index]) == false && this->isSeparators((*(this->_requestString))[this->_index]) == false)
	{
		this->_actualKey += (*(this->_requestString))[this->_index];
		this->_index++;
	}
}

void	parser::value() //1*any octect except ctls
{
	
	if (this->isCTLs((*(this->_requestString))[this->_index]) == true || this->isLWS(this->_index) == true)
		throw Error(PARSER_ERROR);
	
	std::string	res = "";

	this->_ss.pop();
	while (this->_index < this->_requestString->length() && this->isCTLs((*(this->_requestString))[this->_index]) == false && this->isLWS(this->_index) == false)
	{
		res += (*(this->_requestString))[this->_index];
		this->_index++;
	}
	if (this->_newrequest["http"][this->_actualKey].mValue.empty() ==  false)
	{
	  this->_newrequest["http"][this->_actualKey].mList.push_back(this->_newrequest["http"][this->_actualKey].mValue);
	  this->_newrequest["http"][this->_actualKey].mValue = "";
	}
	if (this->_newrequest["http"][this->_actualKey].mList.empty() == false)
	  this->_newrequest["http"][this->_actualKey].mList.push_back(res);
	else
	  this->_newrequest["http"][this->_actualKey] = res;
}

void	parser::header()
{
	this->_ss.pop();
	this->_ss.push(NTS_VALUES);
	this->_ss.push(TS_COLON);
	this->_ss.push(NTS_HTTPTOKEN);
}

void	parser::lws()
{
	if (this->isLWS(this->_index) == false)
		throw Error(PARSER_ERROR);

	this->_ss.pop();
	if (this->_requestString->compare(this->_index, 2, "\r\n") == 0)
		this->_index += 2;
	while ((*(this->_requestString))[this->_index] == ' ' || (*(this->_requestString))[this->_index] == '\t')
		this->_index++;
}

void	parser::valuesLws()
{
	this->_ss.push(NTS_LWS);
}

void	parser::valuesValue()
{
	this->_ss.push(NTS_VALUE);
}

void	parser::epsilon()
{
	this->_ss.pop();
}

void	parser::headers()
{
	this->_ss.push(NTS_HEADER);
	this->_ss.push(TS_CRLF);
}

void	parser::cmdLine()
{
	this->_ss.pop();
	this->_ss.push(NTS_VERSION);
	this->_ss.push(TS_SP);
	this->_ss.push(NTS_URL);
	this->_ss.push(TS_SP);
	this->_ss.push(NTS_METHOD);
}

void	parser::request()
{
	this->_ss.pop();
	this->_ss.push(NTS_HEADERS);
	this->_ss.push(NTS_CMDLINE);
}

void	parser::method()
{
	int i = 0;

	for (; meth[i].size != 0; ++i)
	{
		if (this->_requestString->compare(this->_index, meth[i].size, meth[i].str) == 0)
		{
			this->_ss.pop();
			this->_newrequest["method"] = meth[i].str;
			this->_index += meth[i].size;
			break;
		}
	}
	if (meth[i].size == 0)
		throw Error(PARSER_ERROR);
}

void	parser::url()
{
  
  this->_newrequest["uri"] = "";

	for (; (*(this->_requestString))[this->_index] != ' ' && this->_index < this->_requestString->length(); ++this->_index)
	{
	  this->_newrequest["uri"].mValue += (*(this->_requestString))[this->_index];
	}
	this->_ss.pop();
}

void	parser::version()
{
	if (this->_requestString->compare(this->_index, 5, "HTTP/") != 0)
		throw Error(PARSER_ERROR);

	int nbPoint = 0;
	this->_index += 5;
	this->_newrequest["version"] = "";
	
	for (; nbPoint < 2 && (isNumber((*(this->_requestString))[this->_index]) == true || (*(this->_requestString))[this->_index] == '.'); ++this->_index)
	{
		if ((*(this->_requestString))[this->_index] == '.')
			++nbPoint;
		this->_newrequest["version"].mValue += (*(this->_requestString))[this->_index];
	}
	if (nbPoint >= 2)
		throw Error(PARSER_ERROR);
	this->_ss.pop();
}
