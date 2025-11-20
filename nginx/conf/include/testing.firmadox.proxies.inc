server_name  local-testing.firmadox.cl;
include include/certificados.totalcheck.cl.inc;

#-- Base APP Path...
#===================
location / {
    proxy_pass    http://127.0.0.1:3000/;
}
