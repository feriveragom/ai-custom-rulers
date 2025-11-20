server_name  local-www.chi-e.cl;
include include/certificados.chi-e.cl.inc;

#-- Base APP Path...
#===================
location /emision/ {
    proxy_pass    http://127.0.0.1:3000/;
}

location /favicon_20x20.ico {
    proxy_pass    http://127.0.0.1:3000/favicon_20x20.ico;
}

#-- Emision CHI-e Services...
#============================
location /emision-chie/ {
    proxy_pass    https://canary-www.chi-e.cl/emision-chie/;
}

location /bridge/ {
    proxy_pass    https://canary-www.chi-e.cl/bridge/;
}

location /chie-sse-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-sse-service/;
}

location /chie-search-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-search-service/;
}

location /chie-extractor-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-extractor-service/;
}

location /chie-report-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-report-service/;
}

location /chie-stock-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-stock-service/;
}



location /chie-request-service/ {
    proxy_pass    https://canary-www.chi-e.cl/chie-request-service/;
}