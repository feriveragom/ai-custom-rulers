server_name  canaryy-plataforma.firmadox.cl;

location ~ ^/firmadox(.*) {
    set $proxy_uri /firmadox$1$is_args$args;
    proxy_pass http://127.0.0.1:3000$proxy_uri;
    proxy_set_header host $host;
    proxy_set_header X-Real-IP $remote_addr;
    proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
    proxy_set_header Upgrade $http_upgrade;
    proxy_set_header Connection $connection_upgrade;
    proxy_set_header Origin '';

    proxy_read_timeout 1800s;
    proxy_http_version 1.1;

    proxy_redirect off;
    allow all;
}