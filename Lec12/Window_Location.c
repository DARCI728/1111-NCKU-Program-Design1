#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main() {
    char url[500] = "";
    fgets(url, 500, stdin);  // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url) {
    Location *l = malloc(sizeof(Location));
    l->protocol = calloc(500, sizeof(char));
    l->host = calloc(500, sizeof(char));
    l->port = 0;
    l->pathname = calloc(500, sizeof(char));
    l->search = calloc(500, sizeof(char));
    l->hash = calloc(500, sizeof(char));
    int p, cnt = 0, part = 1;
    char port[500];
    for (int i = 0; i < 500; i++) {
        switch (part) {
            case 1:
                l->protocol[cnt++] = url[i];
                if (url[i + 1] == ':' && url[i + 2] == '/' && url[i + 3] == '/') {
                    if (strcmp(l->protocol, "https") == 0) l->port = 443;
                    i += 3;
                    cnt = 0;
                    part++;
                }
                break;

            case 2:
                l->host[cnt++] = url[i];
                if (url[i + 1] == ':') {
                    i++;
                    cnt = 0;
                    part++;
                } else if (url[i + 1] == '/') {
                    i++;
                    cnt = 0;
                    part += 2;
                } else if (url[i + 1] == '?') {
                    i++;
                    cnt = 0;
                    part += 3;
                } else if (url[i + 1] == '#') {
                    i++;
                    cnt = 0;
                    part += 4;
                } else if (url[i + 1] == '\n' || url[i + 1] == '\0') {
                    part = 10;
                }
                break;

            case 3:
                port[cnt++] = url[i];
                if (url[i + 1] == '/') {
                    l->port = 0;
                    for (int j = 0; j < cnt; j++) {
                        p = port[j] - '0';
                        for (int k = 0; k < cnt - j - 1; k++) p *= 10;
                        l->port += p;
                    }
                    part++;
                    i++;
                    cnt = 0;
                } else if (url[i + 1] == '?') {
                    l->port = 0;
                    for (int j = 0; j < cnt; j++) {
                        p = port[j] - '0';
                        for (int k = 0; k < cnt - j - 1; k++) p *= 10;
                        l->port += p;
                    }
                    i++;
                    cnt = 0;
                    part += 2;
                } else if (url[i + 1] == '#') {
                    l->port = 0;
                    for (int j = 0; j < cnt; j++) {
                        p = port[j] - '0';
                        for (int k = 0; k < cnt - j - 1; k++) p *= 10;
                        l->port += p;
                    }
                    i++;
                    cnt = 0;
                    part += 3;
                } else if (url[i + 1] == '\n' || url[i + 1] == '\0') {
                    l->port = 0;
                    for (int j = 0; j < cnt; j++) {
                        p = port[j] - '0';
                        for (int k = 0; k < cnt - j - 1; k++) p *= 10;
                        l->port += p;
                    }
                    part = 10;
                }
                break;

            case 4:
                if (url[i] == '?')
                    part++;
                else if (url[i] == '#')
                    part += 2;
                else if (url[i] == '\n' || url[i] == '\0')
                    part = 10;
                else
                    l->pathname[cnt++] = url[i];
                if (url[i + 1] == '?') {
                    i++;
                    cnt = 0;
                    part++;
                } else if (url[i + 1] == '#') {
                    i++;
                    cnt = 0;
                    part += 2;
                } else if (url[i + 1] == '\n' || url[i + 1] == '\0') {
                    part = 10;
                }
                break;

            case 5:
                l->search[cnt++] = url[i];
                if (url[i + 1] == '#') {
                    i++;
                    cnt = 0;
                    part++;
                } else if (url[i + 1] == '\n' || url[i + 1] == '\0') {
                    part = 10;
                }
                break;

            case 6:
                l->hash[cnt++] = url[i];
                if (url[i + 1] == '\n' || url[i + 1] == '\0') {
                    part = 10;
                }
                break;

            default:
                break;
        }
    }
    return l;
}