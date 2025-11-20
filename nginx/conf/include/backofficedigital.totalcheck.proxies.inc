server_name  local-backofficedigital.totalcheck.cl;
include include/certificados.totalcheck.cl.inc;

#-- Base APP Path...
#===================
location /transferencias/ {
    proxy_pass    http://127.0.0.1:3000/;
}