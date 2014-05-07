#ifndef URL_H
# define URL_H

#include <iostream>
#include <map>
#include <stack>

#include "DataTree.hpp"

#define URL_ERROR "Exception : Error while parsing"

class url
{
public:
	enum urlSymbol {
		//terminal symbol
		TS_SP, // ' '
		TS_AT,
		TS_HT, // '\t'
		TS_CRLF, // "\rn"
		TS_DSLASH, // "//"
		TS_SLASH, // "/"
		TS_CR, // '\r'
		TS_LF, // '\n'
		TS_DIEZ, // '#'
		TS_COLON, // ':'
		TS_SEMICOLON, // ';'
		TS_INTERROGATION, // '?'
		TS_LWS, // [CRLF] 1*(SP | HT)
		TS_OTHER, //invalid token
		TS_EOF, // '\0'

		//non-terminal symbol
		NTS_HOSTPORT,
		NTS_HOST,
		NTS_HAVEPORT,
		NTS_PORT,
		NTS_SEGMENTS,
		NTS_SEGMENT,
		NTS_PARAMS,
		NTS_PARAM,
		NTS_SEGVALUE,
		NTS_ABSPATH,
		NTS_NETPATH,
		NTS_AUTHORITY,
		NTS_USERINFO,
		NTS_URL,
		NTS_SCHEME,
		NTS_QUERY,
		NTS_FRAGMENT,
		NTS_QUERYS,
		NTS_FRAGMENTS,

		//non-terminal basic symbol (word, int, etc)
		NTS_LWS,
		NTS_HTTPTOKEN
	};

	enum rules {
		DEFAULT,
		EPSILON,
		URL,
		NETPATH,
		ABSPATH,
		SEGMENT,
		SEGMENTS,
		SEGMENTVALUE,
		PARAMS,
		PARAM,
		HOST,
		PORT,
		HOSTPORT,
		HAVEPORT,
		SCHEME,
		QUERY,
		QUERYS,
		FRAGMENT,
		FRAGMENTS
	};

	urlSymbol										lexer();
	void											parse(zia::api::DataTree &d);
	url();
protected:

private:
	void											defaulted();
	void											epsilon();
	void											urlAbsURI();
	void											lws();
	bool											isCTLs(char c) const;
	bool											isSeparators(char c) const;
	bool											isChar(char c) const;
	bool											isLWS(int i) const;
	bool											isNumber(char c) const;
	void											hostport();
	void											haveport();
	void											port();
	void											host();
	void											absPath();
	void											segments();
	void											segment();
	void											params();
	void											pchar();
	bool											isAlpha(char c) const;
	bool											isPChar();
	bool											isEscaped();
	bool											isHex(char c) const;
	bool											isMark(char c) const;
	void											param();
	void											segmentvalue();
	void											netPath();
	void											authorithy();
	bool											isScheme();
	void											scheme();
	void											userInfo();
	bool											isUserInfo();
	bool											isReserved(char c) const;
	bool											isUric();
	void											query();
	void											fragment();
	void											headerHost();
	void											querys();
	void											fragments();
        std::map<urlSymbol, std::map<urlSymbol, int> >                                          _table; // LL parser table, maps < non-terminal, terminal> pair to action
        std::stack<urlSymbol>                                           			_ss;    // symbol stack
        int											_nbParseMethod;
        std::string                                     					_actualString;
        unsigned int                                            				_index;
	std::string										_actualKey;
	std::string										*_url;
        zia::api::DataTree                                      				*_data;
}; //! class parser

#endif //! URL_H
