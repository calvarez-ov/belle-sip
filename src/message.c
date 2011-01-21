/*
	belle-sip - SIP (RFC3261) library.
    Copyright (C) 2010  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "belle_sip_messageParser.h"
#include "belle_sip_messageLexer.h"
#include "belle_sip_internal.h"
typedef struct _headers_container {
	const char* name;
	belle_sip_list_t* header_list;
} headers_container_t;

static headers_container_t* belle_sip_message_headers_container_new(const char* name) {
	headers_container_t* headers_container = belle_sip_new0(headers_container_t);
	headers_container->name= belle_sip_strdup(name);
}

struct _belle_sip_message {
	belle_sip_object_t base;
	belle_sip_list_t* header_list;
	belle_sip_list_t* headernames_list;
};

static int belle_sip_headers_container_comp_func(const headers_container_t *a, const char*b) {
	return strcmp(a->name,b);
}
static void belle_sip_message_init(belle_sip_message_t *message){
	belle_sip_object_init_type(message,belle_sip_message_t);
}

headers_container_t* belle_sip_headers_container_get(belle_sip_message_t* message,const char* header_name) {
	belle_sip_list_t *  result = belle_sip_list_find_custom(	message->header_list
															, (belle_sip_compare_func)belle_sip_headers_container_comp_func
															, header_name);
	return result?(headers_container_t*)(result->data):NULL;
}
void belle_sip_message_add_header(belle_sip_message_t *message,belle_sip_header_t* header) {

}
struct _belle_sip_request {
	belle_sip_message_t message;
};

static void belle_sip_request_destroy(belle_sip_request_t* request) {

}
BELLE_SIP_NEW(request,message)
BELLE_SIP_PARSE(request)

void belle_sip_request_set_uri(belle_sip_request_t* request,belle_sip_uri_t* uri) {

}
void belle_sip_request_set_method(belle_sip_request_t* request,const char* method) {

}
int belle_sip_message_is_request(belle_sip_message_t *msg){
	return 0;
}

int belle_sip_message_is_response(belle_sip_message_t *msg){
	return 0;
}

belle_sip_header_t *belle_sip_message_get_header_last(belle_sip_message_t *msg, const char *header_name){
	return NULL;
}

char *belle_sip_message_to_string(belle_sip_message_t *msg){
	return NULL;
}
