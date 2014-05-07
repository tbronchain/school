#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include <stack>

#include "DataTree.hpp"

#define PARSER_ERROR "Exception : Error while parsing"

class parser
{
public:
	enum symbol {
		//terminal symbol
		TS_SP, // ' '
		TS_HT, // '\t'
		TS_CRLF, // "\rn"
		TS_CR, // '\r'
		TS_LF, // '\n'
		TS_COLON, // ':'
		TS_LWS, // [CRLF] 1*(SP | HT)
		TS_OTHER, //invalid token
		TS_EOF, // '\0'

		//non-terminal symbol
		NTS_REQUEST,
		NTS_CMDLINE,
		NTS_HEADERS,
		NTS_HEADER,
		NTS_VALUES,
		NTS_URL,
		
		//non-terminal basic symbol (word, int, etc)
		NTS_LWS,
		NTS_HTTPTOKEN,
		NTS_METHOD,
		NTS_VERSION,
		NTS_VALUE
	};

	enum rules {
		DEFAULT,
		HTTPTOKEN,
		VALUE,
		HEADER,
		VALUESLWS,
		VALUESVALUE,
		EPSILON,
		LWS,
		HEADERS,
		CMDLINE,
		REQUEST,
		METHOD,
		URL,
		VERSION
	};

	symbol										lexer();	
	void										parse(std::string &strRequest, zia::api::DataTree &);
	//	zia::api::DataTree										parse(std::string &strRequest/*, zia::api::DataTree &d*/);
	parser();
protected:

private:
	void										defaulted();
	void										httpToken();
	void										value();
	void										valuesLws();
	void										valuesValue();
	void										epsilon();
	void										header();
	void										headers();
	void										lws();
	void										cmdLine();
	void										request();
	void										method();
	void										url();
	void										version();
	bool										isCTLs(char c) const;
	bool										isSeparators(char c) const;
	bool										isChar(char c) const;
	bool										isLWS(int i) const;
	bool										isNumber(char c) const;

	std::map<symbol, std::map<symbol, int> >	_table; // LL parser table, maps < non-terminal, terminal> pair to action
	std::stack<symbol>							_ss;    // symbol stack
	int											_nbParseMethod;
	std::string									*_requestString;
	unsigned int								_index;
	zia::api::DataTree							_newrequest;
	std::string									_actualKey;
}; //! class parser


#endif //! PARSER_H
