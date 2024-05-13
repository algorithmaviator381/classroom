#include <iostream>

using namespace std;

namespace log
{
    class Log{
    private:
        int m_loglevel;
    public:
        const int logLevelError = 0;
        const int logLevelWarning = 0;
        const int logLevelEInfo = 0;

        void setlevel(int level){
            m_loglevel = level;
        }

         

    };
}


int main(){

    log::Log log;
    log.setlevel(10);
}