#ifndef DESCRIPTORCONF_H_
# define DESCRIPTORCONF_H_

/*
**  Binary Constants please do not touch the defines...
*/

const static unsigned int SET_READ	= 1;
const static unsigned int SET_WRITE	= 2;
const static unsigned int SET_ERROR	= 4;
const static unsigned int READY_READ	= 1;
const static unsigned int READY_WRITE	= 2;
const static unsigned int READY_ERROR	= 4;

class DescriptorConf
{
public:
    DescriptorConf();
    ~DescriptorConf();

    void	setDescriptor(const int);

    void	setRead();
    void	setWrite();
    void	setError();

    void	setReadyRead();
    void	setReadyWrite();
    void	setReadyError();

    int		getDescriptor();

    bool	getRead();
    bool	getWrite();
    bool	getError();

    bool	readyRead();
    bool	readyWrite();
    bool	readyError();

private:
    int		flagIn_;
    int		flagOut_;
    int		descriptor_;
};

#endif // DESCRIPTORCONF_H_
