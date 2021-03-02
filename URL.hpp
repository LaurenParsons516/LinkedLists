#include <string>

using namespace std;

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream);

class URL
{
    private:
        string theURL;
        
    
    public:
        URL(string theURL);
        string getContents();
};