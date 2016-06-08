/*

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#ifndef HuginnCore_h
#define HuginnCore_h

#include <Arduino.h>
#include <ArduinoJson.h>

#define MAX_BUFFER_SIZE 1000

struct telegramMessage{
  String text;
  String chat_id;
  String sender;
  String date;
  int update_id;
};

class HuginnCore
{
  public:
    HuginnCore(String, int);
    virtual String sendPost(String location, String options, JsonObject& payload) = 0;
  protected:
    String _host;
    int _port;
};

#endif
