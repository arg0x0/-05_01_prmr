// Copyright (c) Localhost Networks
// All rights reserved
//
// This software is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation. For the terms of this
// license, see http://www.gnu.org/licenses/
//
// You are free to use this software under the terms of the GNU General
// Public License, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// SPDX-License-Identifier: GPL-2.0-only

#include <stdlib.h>
#include <string.h>
#include "mongoose.h"

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  if (ev != MG_EV_HTTP_MSG) {
    return;
  }

  struct mg_http_message *hm = (struct mg_http_message *) ev_data;

  if (mg_http_match_uri(hm, "/api/xml")) {
    mg_http_reply(c, 200, "Content-Type: application/xml\r\n", "<?xml version=\"1.0\" encoding=\"utf-8\"?><response><status>ok</status></response>");
    return;
  }

  if (mg_http_match_uri(hm, "/api/json")) {
    mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"status\": \"ok\"}");
    return;
  }

  if (mg_http_match_uri(hm, "/api/json")) {
    mg_http_reply(c, 200, "Content-Type: application/json\r\n", "{\"status\": \"ok\"}");
    return;
  }

  if (mg_http_match_uri(hm, "/api/xml")) {
    mg_http_reply(c, 200, "Content-Type: application/xml\r\n", "<?xml version=\"1.0\" encoding=\"utf-8\"?><response><status>ok</status></response>");
    return;
  }

  mg_http_reply(c, 200, "", "%s\n", "It works!");
}

int main(void) {
  struct mg_mgr mgr;
  mg_mgr_init(&mgr);
  mg_http_listen(&mgr, "http://0.0.0.0:8888", fn, &mgr);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);
  return EXIT_SUCCESS;
}

