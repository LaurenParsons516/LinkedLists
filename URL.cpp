#include "URL.hpp"
#include <curl/curl.h>
#include <iostream>

using namespace std;

string contents = "";

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    //make it so ptr can be treated as a modern string
    int numbytes = size*nmemb;
    // The data is not null-terminated, so get the last character, and replace
    // it with '\0'.
    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';
    //end of ptr manipulation to make it work as a modern string

    contents.append((char *)ptr);
    contents.append(1,lastchar);
    *((char *) ptr + numbytes - 1) = lastchar;  // Might not be necessary.
    return size*nmemb;
}

URL::URL(string theURL)
{
    this->theURL = theURL;
}

string URL::getContents()
{
    contents = "";
    CURL* curl = curl_easy_init();
    if(curl) //if the variable has something in it
    {
        // Tell libcurl the URL
        curl_easy_setopt(curl,CURLOPT_URL, this->theURL.c_str());
        // Tell libcurl what function to call when it has data
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,handle_data); //what function should I "callback" when I get data
        // Do it!
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0) //if the error code is 0, everything went well
        {
            return contents;
        }
        else
        {
            cerr << "Error: " << res << endl;  
        }
    }
    return "NO CONTENTS!!!";
}