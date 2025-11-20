server_name  canaryy-franciscovaras.mesonelectronico.cl;

location ~ ^/meson/app(.*) {
    set $proxy_uri /meson/app$1$is_args$args;
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

location ~ ^/meson/static(.*) {
    set $proxy_uri /meson/static$1$is_args$args;
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

location ~ ^/meson/live(.*) {
    set $proxy_uri /meson/live$1$is_args$args;
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