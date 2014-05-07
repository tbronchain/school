-include Makefile.rules

-include Makefile.files

##SRC=					\
##main.cpp				\
##Controller.cpp			\
##Client.cpp				\
##DescriptorWatcher.cpp			\
##Server.cpp				\
##DescriptorConf.cpp			\
##Read.cpp				\
##Write.cpp				\
##Task.cpp				\
##DescriptorReader.cpp			\
##CommandManager.cpp			\
##Socket/SocketUnix.cpp			\
##Mutex/MutexUnix.cpp			\

OBJ=$(SRC:.cpp=.o)
INCLUDE=				\
-I./ConditionVariable/			\
-I./Core/				\
-I./Error/				\
-I./IPC/				\
-I./LibManager/				\
-I./Mutex/				\
-I./Others/				\
-I./Parser/				\
-I./Socket/				\
-I./Stat/				\
-I./Thread/				\
-I./Filesystem/				\
-I./XmlParser/

all: $(PROJ)

$(PROJ): $(OBJ)
	$(CXX) $(LDFLAGS) $(DEBUG) $(OBJ) -o $(PROJ)

%.o: %.cpp
	$(CXX) $(LDFLAGS) $(DEBUG) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

distclean: clean
	echo $(PROJ)
	rm -f $(PROJ)

clean:
	find . \( -name '*.o' -o -name '*.core' \) -exec rm -f {} \;
	find . \( -name '*~' -o -name '*#' \) -exec rm -f {} \;

re: distclean all
