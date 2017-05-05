#include "comm.h"
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void send_data(double leq[])
{
	char temp[30], postdata[200]="data= "; // post field name is given
	CURL *curl;
	CURLcode res;
	int i;
	// prepare the post data

	for(i=0; i<8; i++) //this for loop prepare the post string 
	{
		// in the sprintf function there is a ternary operator
		sprintf(temp, (i==7)?"%.2f":"%.2f;", leq[i]);
		strcat(postdata, temp); // append temp to data
	} // end of for
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl) 
	{	// set URL of server page 
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		// set POST data
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
		// perform a submit
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res)); // output error
		curl_easy_cleanup(curl); //clean up handler
	}
	curl_global_cleanup(); //globaly ending curl 
}
