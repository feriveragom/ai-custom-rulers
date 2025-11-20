#-- AlbertoApi Services Reverse Proxies...
#=========================================
location /userservice/ {
    proxy_pass  https://canary-web.albertcs.com/userservice/;
}
location /nodeservice/ {
    proxy_pass  https://canary-web.albertcs.com/nodeservice/;
}
location /searchservice/ {
    proxy_pass  https://canary-web.albertcs.com/searchservice/;
}
location /workflowservice/ {
    proxy_pass  https://canary-web.albertcs.com/workflowservice/;
}
location /transformationservice/ {
   proxy_pass	https://canary-web.albertcs.com/transformationservice/;
}

# -- APi APP...
#======================
location /api/ {
    proxy_pass    https://canary-web.albertcs.com/api/;
}

# -- Auth APP...
#======================
location ~ ^/auth(.*) {
    proxy_pass    https://canary-web.albertcs.com/auth$1$is_args$args;
    proxy_set_header host $host;
    proxy_read_timeout 1800s;
}

# -- Accounts APP...
#======================
location /accounts/ {
    proxy_pass    https://canary-web.albertcs.com/accounts/;
}

#-- MicroFronts...
#=================
location /microfront/ {
    proxy_pass https://canary-web.albertcs.com/microfront/;
}

#-- IDAi-services...
#===================
#location /idai-service/ {
#    proxy_pass  https://canary-web.albertcs.com/idai-service/;
#}

#-- Transferencias-services...
#=============================
location /transferenciaservice/ {
    proxy_pass  https://canary-web.albertcs.com/transferenciaservice/;
}
