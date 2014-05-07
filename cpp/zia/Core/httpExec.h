#ifndef HTTPEXEC_H_
# define HTTPEXEC_H_

# include <iostream>
# include <map>
# include <string>

# include "IFileSystem.h"
# include "Client.h"

class	httpExec
{
public:
	typedef	void (httpExec::*EXECPTR)(Client&);

	httpExec();
	~httpExec();

	std::map<std::string, EXECPTR>&		getMap();

        bool                                    isReadable(const std::string& file) const;

        void                                    eGet(Client&);
        void                                    ePut(Client&);
        void                                    ePost(Client&);
        void                                    eHead(Client&);
        void                                    eOptions(Client&);
        void                                    eDelete(Client&);
        void                                    eTrace(Client&);
        void                                    eConnect(Client&);

        void                                    checkUrl(Client& c, std::string& file, bool& run, bool& isDir, bool& isFile, std::list<std::string>& dir_content);
        void                                    setHeader(Client&, const char* code, const char* reason, bool error);

        bool                                    checkExtension(const std::string& item, const char* ext);
        void                                    execPhpMod(Client& c);

private:
        std::map<std::string, EXECPTR>          map_;
	std::map<std::string, std::string>	mapext_;
        IFileSystem*				fs_;
};

#endif // !HTTPEXEC_H_
