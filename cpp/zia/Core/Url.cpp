#include "Error.hpp"
#include "Url.h"

typedef void	(url::*methodPtr)();

struct				lexerUrlSymbol 
{
	const char*		str;
	unsigned int	size;
	url::urlSymbol	sym;
};

lexerUrlSymbol	lexUrl[] =
{
	{"\r\n", 2, url::TS_CRLF},
	{"//", 2, url::TS_DSLASH},
	{"/", 1, url::TS_SLASH},
	{"\n", 1, url::TS_LF},
	{"\r", 1, url::TS_CR},
	{":", 1, url::TS_COLON},
	{"#", 1, url::TS_DIEZ},
	{";", 1, url::TS_SEMICOLON},
	{"@", 1, url::TS_AT},
	{" ", 1, url::TS_SP},
	{" ", 1, url::TS_HT},
	{"?", 1, url::TS_INTERROGATION},
	{"\0", 1, url::TS_EOF},
	{"", 0, url::TS_OTHER}
};

url::url()
{
	this->_index = 0;
	this->_nbParseMethod = 18;
	//this->_table[NTS_URL][TS_OTHER] = URL;
	this->_table[NTS_QUERYS][TS_INTERROGATION] = QUERYS;
	this->_table[NTS_QUERY][TS_OTHER] = QUERY;
	this->_table[NTS_QUERYS][TS_DIEZ] = EPSILON;
	this->_table[NTS_QUERYS][TS_EOF] = EPSILON;
	this->_table[NTS_FRAGMENTS][TS_DIEZ] = FRAGMENTS;
	this->_table[NTS_FRAGMENT][TS_OTHER] = FRAGMENT;
	this->_table[NTS_FRAGMENTS][TS_EOF] = EPSILON;
	this->_table[NTS_SCHEME][TS_OTHER] = SCHEME;
	this->_table[NTS_URL][TS_DSLASH] = NETPATH;
	this->_table[NTS_URL][TS_SLASH] = ABSPATH;
	this->_table[NTS_SEGMENT][TS_OTHER] = SEGMENT;
	this->_table[NTS_SEGMENT][TS_INTERROGATION] = EPSILON;
	this->_table[NTS_SEGMENT][TS_DIEZ] = EPSILON;
	this->_table[NTS_SEGMENT][TS_EOF] = EPSILON;
	this->_table[NTS_SEGMENTS][TS_SLASH] = SEGMENTS;
	this->_table[NTS_SEGMENTS][TS_INTERROGATION] = EPSILON;
	this->_table[NTS_SEGMENTS][TS_EOF] = EPSILON;
	this->_table[NTS_SEGMENTS][TS_DIEZ] = EPSILON;
	this->_table[NTS_SEGVALUE][TS_OTHER] = SEGMENTVALUE;
	this->_table[NTS_PARAMS][TS_SEMICOLON] = PARAMS;
	this->_table[NTS_PARAMS][TS_SLASH] = EPSILON;
	this->_table[NTS_PARAMS][TS_DIEZ] = EPSILON;
	this->_table[NTS_PARAMS][TS_EOF] = EPSILON;
	this->_table[NTS_PARAMS][TS_INTERROGATION] = EPSILON;
	this->_table[NTS_PARAM][TS_SEMICOLON] = EPSILON;
	this->_table[NTS_PARAM][TS_SLASH] = EPSILON;
	this->_table[NTS_PARAM][TS_DIEZ] = EPSILON;
	this->_table[NTS_PARAM][TS_EOF] = EPSILON;
	this->_table[NTS_PARAM][TS_INTERROGATION] = EPSILON;
	this->_table[NTS_PARAM][TS_OTHER] = PARAM;
	this->_table[NTS_HOSTPORT][TS_OTHER] = HOSTPORT;
	this->_table[NTS_HOST][TS_OTHER] = HOST;
	this->_table[NTS_HAVEPORT][TS_INTERROGATION] = EPSILON;
	this->_table[NTS_HAVEPORT][TS_SLASH] = EPSILON;
	this->_table[NTS_HAVEPORT][TS_DIEZ] = EPSILON;
	this->_table[NTS_HAVEPORT][TS_COLON] = HAVEPORT;
	this->_table[NTS_HAVEPORT][TS_EOF] = EPSILON;
	this->_table[NTS_PORT][TS_OTHER] = PORT;
}

url::urlSymbol	url::lexer()
{
	url::urlSymbol	res = TS_OTHER;

	for (int i = 0; lexUrl[i].sym != TS_OTHER; ++i)
	{
		if (this->_url->compare(this->_index, lexUrl[i].size, lexUrl[i].str) == 0)
		{
			res = lexUrl[i].sym;
			break;
		}
	}
	if (res == TS_OTHER && (*this->_url)[this->_index] == '\0')
		res = TS_EOF;
	return res;
}

void					url::parse(zia::api::DataTree &d)
{
	methodPtr			tableMethodPtr[] = {&url::defaulted, &url::epsilon, &url::urlAbsURI, &url::netPath, &url::absPath, &url::segment, &url::segments, &url::segmentvalue, &url::params, &url::param, &url::host, &url::port, &url::hostport, &url::haveport, &url::scheme, &url::query, &url::querys, &url::fragment, &url::fragments};

	this->_data = &d;
	if ((*this->_data).has("http") && (*this->_data)["http"].has("Host"))
		this->headerHost();
	
	this->_index = 0;
	this->_url = &((*this->_data)["uri"].mValue);
	(*this->_url) += '\0';
	url::urlSymbol symm = url::TS_OTHER;

	// init stack
	while (this->_ss.empty() == false)
		this->_ss.pop();
	this->_ss.push(TS_EOF);
	this->_ss.push(NTS_FRAGMENTS);
	this->_ss.push(NTS_QUERYS);
	this->_ss.push(NTS_URL);
	if (this->isAlpha((*this->_url)[0]) && this->isScheme() == true)
	{
		this->_ss.push(TS_COLON);
		this->_ss.push(NTS_SCHEME);
	}
	

	while (this->_ss.size() > 0 && this->_index < this->_url->size())
	{
		if ((symm = lexer()) == this->_ss.top())
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
				throw Error(URL_ERROR);
			else
			{
				(this->*tableMethodPtr[this->_table[this->_ss.top()][lexer()]])();
			}
		}
	}
	if (this->_ss.size() > 0 && this->_index >= this->_url->size())
		throw Error(URL_ERROR);
}

void url::headerHost()
{
	methodPtr			tableMethodPtr[] = {&url::defaulted, &url::epsilon, &url::urlAbsURI, &url::netPath, &url::absPath, &url::segment, &url::segments, &url::segmentvalue, &url::params, &url::param, &url::host, &url::port, &url::hostport, &url::haveport};

	this->_index = 0;
	this->_url = &((*this->_data)["http"]["Host"].mValue);
	(*this->_url) += '\0';
	// init stack
	while (this->_ss.empty() == false)
		this->_ss.pop();
	this->_ss.push(TS_EOF);
	this->_ss.push(NTS_HOSTPORT);

	while (this->_ss.size() > 0 && this->_index < this->_url->size())
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
				throw Error(URL_ERROR);
			else
			{
				(this->*tableMethodPtr[this->_table[this->_ss.top()][lexer()]])();
			}
		}
	}
	if (this->_ss.size() > 0 && this->_index >= this->_url->size())

		throw Error(URL_ERROR);
}

void	url::defaulted()
{
	throw Error(URL_ERROR);
}

bool	url::isCTLs(char c) const //<tout caractère de contrôle US-ASCII (octets 0 - 31) et DEL (127)>
{
	if ((c <= 31 && c >= 0) || c == 127)
		return (true);
	return (false);
}

bool	url::isSeparators(char c) const // "(" | ")" | "<" | ">" | "@" | "," | ";" | ":" | "\" | <"> | "/" | "[" | "]" | "?" | "=" | "{" | "}" | SP | HT
{
	std::string	separators = "()<>@,;:\"\\/[]?={} \t";

	if (separators.find_first_of(c) != std::string::npos)
		return (true);
	return (false);
}

bool	url::isChar(char c) const // <tout caractère US-ASCII (octets 0 - 127)>
{
	return c >= 0;
}

bool	url::isLWS(int i) const
{
	if (this->_url->compare(i, 2, "\r\n") == 0)
		i += 2;
	if ((*(this->_url))[i] == ' ' || (*(this->_url))[i] == '\t')
		return (true);
	return (false);
}

bool	url::isNumber(char c) const
{
	if (c <= '9' && c >= '0')
		return (true);
	return (false);
}

bool	url::isAlpha(char c) const
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

bool	url::isHex(char c) const
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
		return true;
	return false;
}

bool	url::isEscaped()
{
	if (this->_index + 2 < this->_url->length() 
		&& (*this->_url)[this->_index] == '%' 
		&& this->isHex((*this->_url)[this->_index + 1]) == true
		&& this->isHex((*this->_url)[this->_index + 2]) == true)
		return true;
	return false;
}

bool	url::isMark(char c) const
{
	if (c == '-' || c == '_' || c == '.' || c == '!' || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')')
		return true;
	return false;
}

bool	url::isPChar()
{
	if (isNumber((*(this->_url))[this->_index]) == true
		|| isAlpha((*(this->_url))[this->_index]) == true
		|| isEscaped() == true
		|| isMark((*(this->_url))[this->_index]) == true
		|| (*(this->_url))[this->_index] == ':'
		|| (*(this->_url))[this->_index] == '@'
		|| (*(this->_url))[this->_index] == '&'
		|| (*(this->_url))[this->_index] == '='
		|| (*(this->_url))[this->_index] == '+'
		|| (*(this->_url))[this->_index] == '$'
		|| (*(this->_url))[this->_index] == ',')
		return true;
	return false;
}

bool	url::isScheme()
{
	unsigned int	i = this->_index;

	if (i > this->_url->length() || isAlpha((*this->_url)[i]) == false)
		throw Error(URL_ERROR);

	for (; i < this->_url->length()
		&& (isAlpha((*this->_url)[i]) == true 
		|| isNumber((*this->_url)[i]) == true 
		|| (*this->_url)[i] == '+'
		|| (*this->_url)[i] == '-'
		|| (*this->_url)[i] == '.')
		;++i)
	{
	}

	if (i < this->_url->length() && (*this->_url)[i] == ':')
		return true;
	return false;
}

bool	url::isUserInfo()
{
	unsigned int	i = this->_index;

	if (i > this->_url->length() || isAlpha((*this->_url)[i]) == false)
		throw Error(URL_ERROR);

	for (; i < this->_url->length()
		&& (isAlpha((*this->_url)[i]) == true 
		|| isNumber((*this->_url)[i]) == true 
		|| isEscaped() == true 		
		|| isMark((*this->_url)[i]) == true 
		|| (*this->_url)[i] == ';'
		|| (*this->_url)[i] == ':'
		|| (*this->_url)[i] == '&'
		|| (*this->_url)[i] == '='
		|| (*this->_url)[i] == '+'
		|| (*this->_url)[i] == '$'
		|| (*this->_url)[i] == ',')
		;++i)
	{
	}

	if (i < this->_url->length() && (*this->_url)[i] == '@')
		return true;
	return false;
}

bool	url::isReserved(char c) const
{
	if (c == ';' || c == '/' || c == '?' || c == ':' || c == '@' || c == '&' || c == '=' || c == '+' || c == '$' || c == ',')
		return true;
	return false;
}

bool	url::isUric()
{
	if (this->isEscaped() == true
		|| this->isMark((*(this->_url))[this->_index]) == true
		|| this->isAlpha((*(this->_url))[this->_index]) == true
		|| this->isNumber((*(this->_url))[this->_index]) == true
		|| this->isReserved((*(this->_url))[this->_index]) == true)
		return true;
	return false;
}

void	url::lws()
{
	if (this->isLWS(this->_index) == false)
		throw Error(URL_ERROR);

	this->_ss.pop();
	if (this->_url->compare(this->_index, 2, "\r\n") == 0)
		this->_index += 2;
	while ((*(this->_url))[this->_index] == ' ' || (*(this->_url))[this->_index] == '\t')
		this->_index++;
}

void	url::epsilon()
{
	this->_ss.pop();
}

void	url::urlAbsURI()
{
	(*(this->_data))["uri"] = "";

	for (; (*(this->_url))[this->_index] != ' ' && this->_index < this->_url->length(); ++this->_index)
	{
		(*(this->_data))["uri"].mValue += (*(this->_url))[this->_index];
	}
	this->_ss.pop();
}

void	url::hostport()
{
	this->_ss.pop();
	this->_ss.push(NTS_HAVEPORT);
	this->_ss.push(NTS_HOST);
}

void	url::haveport()
{
	this->_ss.pop();
	this->_ss.push(NTS_PORT);
	this->_ss.push(TS_COLON);
}

void	url::port()
{
	if (this->isNumber((*(this->_url))[this->_index]) == false)
		throw Error(URL_ERROR);

	this->_ss.pop();
	for (; this->isNumber((*(this->_url))[this->_index]) == true; ++this->_index)
	{
		(*this->_data)["url"]["port"].mValue += (*(this->_url))[this->_index];
	}
}

void	url::host()
{
	this->_ss.pop();

	for (; (*(this->_url))[this->_index] != '\0' && (*(this->_url))[this->_index] != '/' && (*(this->_url))[this->_index] != ':'; ++this->_index)
	{
		(*this->_data)["url"]["host"].mValue += (*(this->_url))[this->_index];
	}
}

void	url::absPath()
{
	this->_ss.pop();
	this->_ss.push(NTS_SEGMENTS);
	this->_ss.push(NTS_SEGMENT);
	this->_ss.push(TS_SLASH);
}

void	url::segments()
{
	this->_ss.push(NTS_SEGMENT);
	this->_ss.push(TS_SLASH);
}

void	url::segment()
{
	this->_ss.pop();
	this->_ss.push(NTS_PARAMS);
	this->_ss.push(NTS_SEGVALUE);
}

void	url::params()
{
	this->_ss.push(NTS_PARAM);
	this->_ss.push(TS_SEMICOLON);
}

void	url::param()
{
	if (this->isPChar() == false)
		throw Error(URL_ERROR);

	this->_ss.pop();
	for (; this->isPChar() == true; ++this->_index)
	{
		(*this->_data)["url"][this->_actualString].mValue += (*this->_url)[this->_index];
	}
}

void	url::segmentvalue()
{
	std::string		seg = "";

	if (this->isPChar() == false)
		throw Error(URL_ERROR);

	this->_ss.pop();
	for (; this->isPChar() == true; ++this->_index)
	{
		seg += (*this->_url)[this->_index];
	}
	(*this->_data)["url"].mList.push_back(seg);
	this->_actualString = seg;
}

void	url::netPath()
{
	this->_ss.pop();
	this->_ss.push(NTS_ABSPATH);
	this->_ss.push(NTS_AUTHORITY);
	this->_ss.push(TS_DSLASH);
}

void	url::authorithy()
{
	this->_ss.pop();
	this->_ss.push(NTS_HOSTPORT);
	this->_ss.push(NTS_USERINFO);
}

void	url::scheme()
{
	this->_ss.pop();
	if (this->isScheme() == false)
		this->_ss.pop();
	else
	{
		for (; (*this->_url)[this->_index] != ':'; ++this->_index)
			(*this->_data)["url"]["scheme"].mValue += (*this->_url)[this->_index];
	}
}

void	url::userInfo()
{
	this->_ss.pop();
	if (this->isUserInfo() == false)
		this->_ss.pop();
	else
	{
		for (; (*this->_url)[this->_index] != '@'; ++this->_index)
			(*this->_data)["url"]["userinfo"].mValue += (*this->_url)[this->_index];
	}
}

void	url::query()
{
	this->_ss.pop();

	for (;isUric(); ++this->_index)
	{
		(*this->_data)["url"]["query"].mValue += (*this->_url)[this->_index];
	}
}

void	url::querys()
{
	this->_ss.pop();
	this->_ss.push(NTS_QUERY);
	this->_ss.push(TS_INTERROGATION);
}

void	url::fragment()
{
	this->_ss.pop();

	for (;isUric(); ++this->_index)
	{
		(*this->_data)["url"]["fragment"].mValue += (*this->_url)[this->_index];
	}
}

void	url::fragments()
{
	this->_ss.pop();
	this->_ss.push(NTS_FRAGMENT);
	this->_ss.push(TS_DIEZ);
}