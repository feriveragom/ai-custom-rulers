server_name  local-backofficeautomotriz.totalcheck.cl;
include include/certificados.totalcheck.cl.inc;

#-- Base APP Path...
#===================
location /accounts/ {
    proxy_pass    http://127.0.0.1:3000/;
}