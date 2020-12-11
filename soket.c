#include <curl/curl.h>
#include <stdio.h>

void get_page(const char* url, const char* file_name)
{
  CURL* easyhandle = curl_easy_init();

  curl_easy_setopt( easyhandle, CURLOPT_URL, url ) ;

  FILE* file = fopen( file_name, "w");

  curl_easy_setopt( easyhandle, CURLOPT_WRITEDATA, file) ;

  curl_easy_perform( easyhandle );

  curl_easy_cleanup( easyhandle );

  fclose(file);

}

int main()
{
  get_page( "http://127.0.0.1/index.html", "index.html" ) ;

  return 0;
}