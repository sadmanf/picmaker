#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIXEL_FORMAT_BYTES 20

const int h = 512;
const int w = 512;
const int colors = 255;

int prep(double d) {
    return abs((int) d) % colors;
}

int main(int argc, char *argv[]) {
    char buf[PIXEL_FORMAT_BYTES * w];
    // Open output file
    FILE *fd = fopen("image.ppm", "w");
    if (fd == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(1);
    }
    // Write metadata
    sprintf(buf, "P3\n%d\n%d\n%d\n", w, h, colors);
    fwrite(buf, strlen(buf), sizeof(char), fd);
    int r, g, b;
    int i, u;
    char line_buf[PIXEL_FORMAT_BYTES * w];
    r = g = b = 0;
    for (i = 0;i < h;++i) {
        buf[0] = '\0';
        for (u = 0;u < w;++u) {
            if (i < h / 2) {
                // TL
                if (u < w / 2) {
                    r = colors ^ i % (h / 2) & colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                    g = colors ^ i % (h / 2) & colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                    b = colors ^ i % (h / 2) & colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                }
                // TR
                else {
                    r = colors ^ i % (h / 2) & colors ^ (u % (w / 2)) | (u % (w / 2));
                    g = colors ^ i % (h / 2) & colors ^ (u % (w / 2)) | (u % (w / 2));
                    b = colors ^ i % (h / 2) & colors ^ (u % (w / 2)) | (u % (w / 2));
                }
            }
            else {
                // BL
                if (u < w / 2) {
                    r = colors ^ i % (h / 2) ^ colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                    g = colors ^ i % (h / 2) ^ colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                    b = colors ^ i % (h / 2) ^ colors ^ (w / 2 - (u % (w / 2))) | (w / 2 - (u % (w / 2)));
                }
                // BR
                else {
                    r = colors ^ i % (h / 2) ^ colors ^ u % (w / 2) | (u % (w / 2));
                    g = colors ^ i % (h / 2) ^ colors ^ u % (w / 2) | (u % (w / 2));
                    b = colors ^ i % (h / 2) ^ colors ^ u % (w / 2) | (u % (w / 2));
                }
            }
            // Green
            r ^= b;
            b ^= g;
            g ^= r;
            sprintf(line_buf, "%d %d %d ", prep(r), prep(g), prep(b));
            strcat(buf, line_buf);
        }
        strcat(buf, "\n");
        fwrite(buf, strlen(buf), sizeof(char), fd);
    }
    return 0;
}
