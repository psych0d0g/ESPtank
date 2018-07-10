#ifndef header_h
#define header_h

String main_page=
"<html>\r\n"
"    <head>\r\n"
"      <style>\r\n"
"        body { background-color: #202020; }\r\n"
"        h2, td, a { color: #95A5A6; }\r\n"
"        p { color: white; }\r\n"
"      </style>\r\n"
"      <title>Aquarium Controller</title>\r\n"
"      <meta charset=\"utf-8\">\r\n"
"      <script src=//cdn.rawgit.com/Mikhus/canvas-gauges/gh-pages/download/2.1.5/all/gauge.min.js></script>\r\n"
"      <script src=\"//ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>\r\n"
"      <script type=\"text/javascript\">\r\n"
"        $(document).ready(function () {\r\n"
"          setInterval(updateGauges, 1000);  \r\n"
"        })\r\n"
"        function updateGauges(){ \r\n"
"          $.ajax({ \r\n"
"            type: 'GET', \r\n"
"            contentType: 'application/json; charset=utf-8',\r\n"
"            url: '/fishtank.json', \r\n"
"            data: {}, \r\n"
"            dataType: 'json',\r\n"
"            success: function (data) { \r\n"
"                tempGauge.value=data.fishtankdata.temperature;\r\n"
"                pwmGauge.value=data.fishtankdata.fan_pwm/250*100;\r\n"
"            }\r\n"
"          });\r\n"
"        }\r\n"
"      </script>\r\n"
"    </head>\r\n"
"    <body>\r\n"
"        <h2>Aquarium Controller</h2>\r\n"
"    <table>\r\n"
"      <tr>\r\n"
"        <td align=\"center\"><strong>Temperature [C]</strong></td>\r\n"
"        <td align=\"center\"><strong>FAN Speed [%]</strong></td>\r\n"
"      <tr>\r\n"
"        <td><canvas id=\"temp_gauge\"></canvas></td>\r\n"
"        <td><canvas id=\"pwm_gauge\"></canvas></td>\r\n"
"      </tr>\r\n"
"    </table>\r\n"
"    <script type=\"text/javascript\">\r\n"
"      var pwmGauge = new RadialGauge({\r\n"
"        renderTo: 'pwm_gauge',\r\n"
"        height: 300,\r\n"
"        units: '%',\r\n"
"        minValue: 0,\r\n"
"        maxValue: 100,\r\n"
"        majorTicks: [\r\n"
"            '0',\r\n"
"            '10',\r\n"
"            '20',\r\n"
"            '30',\r\n"
"            '40',\r\n"
"            '50',\r\n"
"            '60',\r\n"
"            '70',\r\n"
"            '80',\r\n"
"            '90',\r\n"
"            '100'\r\n"
"        ],\r\n"
"        minorTicks: 2,\r\n"
"        valueBox: true,\r\n"
"        animationDuration: 1500,\r\n"
"        animationRule: \"dequint\",\r\n"
"        animatedValue: true\r\n"
"      });\r\n"
"      pwmGauge.draw();\r\n"
"      pwmGauge.value = \"0\";\r\n"
"\r\n"
"      var tempGauge = new RadialGauge({\r\n"
"        renderTo: 'temp_gauge',\r\n"
"        height: 300,\r\n"
"        units: '°C',\r\n"
"        minValue: 20,\r\n"
"        maxValue: 35,\r\n"
"        majorTicks: [\r\n"
"            '20',\r\n"
"            '21',\r\n"
"            '22',\r\n"
"            '23',\r\n"
"            '24',\r\n"
"            '25',\r\n"
"            '26',\r\n"
"            '27',\r\n"
"            '28',\r\n"
"            '29',\r\n"
"            '30',\r\n"
"            '31',\r\n"
"            '32',\r\n"
"            '33',\r\n"
"            '34',\r\n"
"            '35'\r\n"
"        ],\r\n"
"        minorTicks: 5,\r\n"
"        highlights  : [\r\n"
"          {from: 24, to: 26, color: 'rgba(50, 200, 50, .75)'},\r\n"
"          {from: 22, to: 24, color: 'rgba(255, 140, 50, .75)'},\r\n"
"          {from: 20, to: 22, color: 'rgba(255, 50, 50, .75)'},\r\n"
"          {from: 26, to: 28, color: 'rgba(255, 140, 50, .75)'},\r\n"
"          {from: 28, to: 35, color: 'rgba(255, 50, 50, .75)'}\r\n"
"        ],\r\n"
"        valueBox: true,\r\n"
"        animationDuration: 1500,\r\n"
"        animationRule: \"dequint\",\r\n"
"        animatedValue: true\r\n"
"      });\r\n"
"      tempGauge.draw();\r\n"
"      tempGauge.value = \"0\";\r\n"
"    </script>\r\n"
"  </body>\r\n"
"</html>\r\n";

String settings_page=
"<html>\r\n"
"    <head>\r\n"
"      <style>\r\n"
"        body { background-color: #202020; }\r\n"
"        h2, td, a { color: #95A5A6; }\r\n"
"        p { color: white; }\r\n"
"      </style>\r\n"
"      <title>Aquarium Controller</title>\r\n"
"      <meta charset=\"utf-8\">\r\n"
"    </head>\r\n"
"    <body>\r\n"
"        <h2>Aquarium Controller</h2>\r\n"
"        <form method=\"post\" action=\"\">\r\n"
"        <table>\r\n"
"            <tr>\r\n"
"                <td align=\"left\"><strong>Desired water temperature [C]</strong></td>\r\n"
"                <td align=\"left\"><input type=\"text\"name=\"temp\" value=\"\" /></td>\r\n"
"            </tr>\r\n"
"            <tr>\r\n"
"                <td align=\"left\"><strong>Maximum okay offset [C]</strong></td>\r\n"
"                <td align=\"left\"><input type=\"text\" name=\"offset\" value=\"\" /></td>\r\n"
"            </tr>\r\n"
"            <tr>\r\n"
"                <td align=\"left\"><input type=\"submit\" name=\"submit\" value=\"Apply\" /></td>\r\n"
"                <td align=\"left\"></td>\r\n"
"            <tr>\r\n"
"        </table>\r\n"
"</form>\r\n";
#endif

