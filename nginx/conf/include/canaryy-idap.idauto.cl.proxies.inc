server_name  canaryy-idap.idauto.cl;

location /idar-service/ {
    proxy_pass  https://canary-reporte.idauto.cl/idar-service/;
}

location /idai-service/ {
    proxy_pass  https://canary-reporte.idauto.cl/idai-service/;
}

location /idaw-service/ {
    proxy_pass  https://canary-reporte.idauto.cl/idaw-service/;
}

location /idat_dealer/ {
    proxy_pass  https://canary-reporte.idauto.cl/idat_dealer/;
}

location /autocheckservicev3/ {
    proxy_pass  https://canary-reporte.idauto.cl/autocheckservicev3/;
}

location /idap_dealer/ {
    proxy_pass  https://canary-reporte.idauto.cl/idap_dealer/;
}

location /idap_boleta/ {
    proxy_pass  https://canary-reporte.idauto.cl/idap_boleta/;
}

location ~ ^/idabi/(.*) {
	#proxy_pass http://comprador-boleta-informativa-service:8080/cl/idabi/public/$1$is_args$args;
    proxy_pass http://localhost:8081/cl/idabi/public/$1$is_args$args;
}

location /idap/titles/upload_document {
    proxy_pass  https://canary-reporte.idauto.cl/idap/titles/upload_document;
}

location /stream {
    proxy_pass  http://localhost:5555/stream;
}
