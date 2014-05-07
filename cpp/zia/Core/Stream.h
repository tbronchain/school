#ifndef STREAM_H_
# define STREAM_H_

#include <sstream>
#include "AStream.hpp"


class										Stream : public zia::api::AStream
{

public:

	Stream();
	~Stream();
        int									callReader();
	bool									canRead() const;
	void									write(const std::string& str);
	void									write(const char* buff, size_t buffSize);
	size_t									read(char* buff, size_t maxBuffSize);
	void									drop();
	void									dropAll();
	void									flush();
	void									close();
	void									forceClose();

protected:

        std::stringstream                                                       mStream;

};

#endif //!STREAM_H_
