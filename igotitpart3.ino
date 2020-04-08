#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>



const char Main_Page[] PROGMEM = {"<html>\n  <head>\n    <link href=\"https://fonts.googleapis.com/css?family=Baloo+Thambi+2|Comic+Neue&display=swap\" rel=\"stylesheet\">\n    \n    <link href=\"https://fonts.googleapis.com/css?family=Montserrat&display=swap\" rel=\"stylesheet\">\n\n    <link rel=\"stylesheet\" type=\"text/css\" href=\"esp.css\">\n   <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n   <script type=\"text/javascript\">\n      google.charts.load('current', {'packages':['gauge']});\n      google.charts.setOnLoadCallback(drawChart);\n\n      function drawChart() {\n\n        var data = google.visualization.arrayToDataTable([\n          ['Label', 'Value'],\n          ['Water Level', 80],\n          \n         \n        ]);\n\n        var options = {\n          width: 600, height: 200,\n          redFrom: 90, redTo: 100,\n          yellowFrom:75, yellowTo: 90,\n          minorTicks: 5\n        };\n\n        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));\n\n        chart.draw(data, options);\n\n        setInterval(function() {\n          data.setValue(0, 1, 40 + Math.round(60 * Math.random()));\n          chart.draw(data, options);\n        }, 13000);\n        setInterval(function() {\n          data.setValue(1, 1, 40 + Math.round(60 * Math.random()));\n          chart.draw(data, options);\n        }, 5000);\n        setInterval(function() {\n          data.setValue(2, 1, 60 + Math.round(20 * Math.random()));\n          chart.draw(data, options);\n        }, 26000);\n      }\n    </script>\n\n\n\n    <script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n    <script type=\"text/javascript\">\n      google.charts.load('current', {'packages':['corechart']});\n      google.charts.setOnLoadCallback(drawChart);\n\n      function drawChart() {\n        var data = google.visualization.arrayToDataTable([\n          ['Time(mins)', 'Temperature'],\n          ['10',  40     ],\n          ['20',  42     ],\n          ['30',  46      ],\n          ['40',  50   ]\n        ]);\n\n        var options = {\n          title: 'Temperature Variation',\n          curveType: 'function',\n          legend: { position: 'bottom' }\n        };\n\n        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));\n\n        chart.draw(data, options);\n      }\n    </script>\n  </head>\n\n\n  <body>\n\n  \n      <h1>Robofever</h1>\n\n      <h2>Cooler</h2>\n\n       <div class=\"container\">\n\n        <button class=\"speed one\" onclick=\"location.href='speed/one';\" value=\"Speed 1\">\n        Speed-1\n      </button>\n\n\n\n      <button class=\"power on\" onclick=\"location.href='power/on';\" value=\"Power On\">\n        PowerON\n      </button>\n\n\n\n      <button class=\"power off\" onclick=\"location.href='power/off';\" value=\"Power Off\">\n        PowerOFF\n      </button>\n\n     \n\n      \n\n      <button class=\"speed two\" onclick=\"location.href='speed/two';\" value=\"Speed 2\">\n        Speed-2\n      </button>\n      \n    </div>\n\n   \n        \n  <div id=\"test\">\n    <div id=\"chart_div\" style=\"width: 200px; height: 300px;\">\n\n\n      \n    </div>\n\n<div class=\"pump\">\n     <button class=\"pump onn\" onclick=\"location.href='pump/on';\" value=\"Pump On\">\n       PumpON\n      </button>\n\n      <button class=\"pump offf\" onclick=\"location.href='pump/off';\" value=\"Pump Off\">\n        PumpOFF\n      </button>\n\n</div>\n </div>\n      \n    <div id=\"curve_chart\" style=\"width: 900px; height: 500px\">\n         \n    </div>\n\n   \n  \n\n  </body>\n</html>\n"};
const char style_css_main_page[] PROGMEM = {"\np{\n\tbackground: white\n}\nh1{\n\tfont-family: 'Comic Neue', cursive;\n\ttext-align: center;\n\tmargin-top: 20px;\n}\nh2{\n\ttext-align: center;\n\tfont-family: 'Baloo Thambi 2', cursive;\n}\n/*div{\n\tborder: 20px solid #bdc3c7;\n\tmax-width: 700px;\n\twidth:80%;\n\tpadding: 20px;\n\tmargin: 20px auto;\n}*/\n\ndiv{\n\n\tmargin: 20px auto;\n}\nbody{\n\tborder : 2px solid grey;\n\tbackground-size: cover;\n\tbackground-position: center;\n\t/*background-image: url(https://wallpaperaccess.com/download/internet-of-things-1445507);*/\n\tbackground-image: url(https://htmlcolorcodes.com/assets/images/html-color-codes-color-tutorials-hero-00e10b1f.jpg);\n\t/*background-image: url();*/\n\tbackground-color: #c7c4c4\n\n}\n\n\n\n#test{\n\tborder-bottom: 2px solid rgba(100,100,0,0.4);\n}\n\n\nh2{\n\tpadding: 20px;\n\tborder-bottom: 2px solid rgba(100,100,100,0.5);\n}\n\n.container{\n\n\ttext-align: center;\n\n}\n\n.power{\n\tborder: 1px solid #3498db;\n\tbackground: none;\n\tpadding: 10px 20px;\n\tfont-size: 20px;\n\tfont-family: \"montserrat\";\n\tcursor: pointer;\n\tmargin: 10px;\n\ttransition: 0.8s;\n\tposition: relative;\n\toverflow: hidden;\n\n\t\n\n}\n\n.on:hover,.off:hover{\n\tcolor: fff;\n}\n\n.power::before{\n\tcontent: \"\";\n\tposition: absolute;\n\tleft: 0;\n\twidth:100%;\n\theight: 0%;\n\tbackground: #3498db;\n\tz-index : -1;\n\ttransition: 0.8s;\n\n}\n\n.on::before,.off::before{\n\ttop: 0;\n\tborder-radius: 0 0 50% 50%;\n}\n\n.on:hover::before,.off:hover::before{\n\theight: 100%;\n}\n\n\n\n.pump{\n\ttext-align: center;\n}\n\n.onn:hover,.offf:hover{\n\tcolor: #2cfc03;\n}\n\n.speed{\n\n\n  background-color: #4CAF50;\n  border: none;\n  color: white;\n  padding: 20px;\n  text-align: center;\n  text-decoration: none;\n  display: inline-block;\n  font-size: 16px;\n  margin: 4px 2px;\n\n\n}\n\n.one {border-radius: 12px;}\n.two {border-radius: 12px;}\n"};


const char* ssid = "ESP";
const char* password = "987654321";


WebServer server(80);
//
void handleRoot() {
server.send_P(200, "text/HTML", Main_Page);
}
//funcrion for handling esp.css request
void handleCSS(){
server.send_P(200,"text/css",style_css_main_page);
}
void poweron(){
  Serial.println("Device power on");
}
void poweroff(){
  Serial.println("Device power off");
}
void speedone(){
  Serial.println("Speed one");
}
void speedtwo(){
  Serial.println("speedtwo ");
}
void pumpon(){
  Serial.println("pump power on");
}
void pumpoff(){
  Serial.println("pump  power off");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password);
  Serial.println("");

  server.on("/",handleRoot);
  server.on("esp.css",handleCSS);
  server.on("/power/on",poweron);
  server.on("/power/off",poweroff);
  server.on("/speed/one",speedone);
  server.on("/speed/two",speedtwo);
  server.on("/pump/on",pumpon);
  server.on("/pump/off",pumpoff);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}


void loop(void) {

  server.handleClient();
}
