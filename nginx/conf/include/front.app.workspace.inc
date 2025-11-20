location /static/ {
    proxy_pass    http://127.0.0.1:3000/static/;
}

location ~ /main.+\.js {
    proxy_set_header X-Real-IP  $remote_addr;
    proxy_set_header X-Forwarded-For $remote_addr;
    proxy_set_header Host $host;
    proxy_pass http://127.0.0.1:3000;
    allow all;
}

location /sockjs-node/ {
    proxy_set_header X-Real-IP  $remote_addr;
    proxy_set_header X-Forwarded-For $remote_addr;
    proxy_set_header Upgrade $http_upgrade;
    proxy_set_header Connection "upgrade";
    proxy_set_header Host $host;
    proxy_http_version 1.1;
    proxy_redirect off;
    
    proxy_pass http://127.0.0.1:3000/sockjs-node/;
}