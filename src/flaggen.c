#define OLIVEC_IMPLEMENTATION
#include "../deps/olive.c"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../deps/stb_image_write.h"

const char* getFilename(const char* country) {
    const char* str1 = "flags/flag_";
    const char* str2 = country;
    const char* str3 = ".png";

    int len1 = strlen(str1) + strlen(str2) + 1;
    char* filename1 = malloc(sizeof(char) * len1);
    strcpy(filename1, str1);
    strcat(filename1, str2);

    int len2 = strlen(filename1) + strlen(str3) + 1;
    char* filename2 = malloc(sizeof(char) * len2);
    strcpy(filename2, filename1);
    strcat(filename2, str3);

    free(filename1);

    return filename2;
}

int main(int argc, const char* argv[]) {
    int WIDTH = 900;
    int HEIGHT = 600;
    const char* country;

    if (argc >= 3) {
        country = argv[1];
        WIDTH = atoi(argv[2]);
        HEIGHT = atoi(argv[3]);
    } else if (argc >= 2) {
        country = argv[1];
    } else {
        fprintf(stderr, "ERROR: missing required argument: country abbreviation!\n");
        return 1;
    }

    uint32_t pixels[WIDTH * HEIGHT];
    Olivec_Canvas oc = olivec_canvas(pixels, WIDTH, HEIGHT, WIDTH);
    const char* file_path = getFilename(country);

    uint32_t white = OLIVEC_RGBA(255, 255, 255, 255);
    uint32_t black = OLIVEC_RGBA(0, 0, 0, 255);

    if (!strcmp(country, "gr")) {
        uint32_t blue = OLIVEC_RGBA(13, 94, 175, 255);
        int lineheight = HEIGHT / 9;
        olivec_fill(oc, blue);
        olivec_rect(oc, 0, lineheight * 2, WIDTH / 3, lineheight, white);
        olivec_rect(oc, WIDTH / 3 / 2 - lineheight / 2, 0, lineheight, lineheight * 5, white);
        for (double i = lineheight; i + lineheight <= HEIGHT; i += lineheight * 2) {
            if (i >= lineheight * 5) {
                olivec_rect(oc, 0, i, WIDTH, lineheight, white);
            } else {
                olivec_rect(oc, WIDTH / 3, i, 2 * WIDTH / 3, lineheight, white);
            }
        }
    } else if (!strcmp(country, "jp")) {
        uint32_t red = OLIVEC_RGBA(187, 0, 45, 255);
        olivec_fill(oc, white);
        olivec_circle(oc, WIDTH / 2, HEIGHT / 2, HEIGHT / 3, red);
    } else if (!strcmp(country, "id")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 2, red);
    } else if (!strcmp(country, "ng")) {
        olivec_fill(oc, OLIVEC_RGBA(0, 134, 82, 255));
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, white);
    } else if (!strcmp(country, "bd")) {
        olivec_fill(oc, OLIVEC_RGBA(0, 106, 78, 255));
        olivec_circle(oc, WIDTH / 2, HEIGHT / 2, HEIGHT / 3, OLIVEC_RGBA(244, 42, 64, 255));
    } else if (!strcmp(country, "ru")) {
        uint32_t blue = OLIVEC_RGBA(0, 56, 165, 255);
        uint32_t red = OLIVEC_RGBA(213, 43, 30, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, blue);
        olivec_rect(oc, 0, 2 * HEIGHT / 3, WIDTH, HEIGHT / 3, red);
    } else if (!strcmp(country, "de")) {
        uint32_t red = OLIVEC_RGBA(220, 0, 0, 255);
        uint32_t yellow = OLIVEC_RGBA(254, 206, 0, 255);
        olivec_fill(oc, black);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, 2 * HEIGHT / 3, WIDTH, HEIGHT / 3, OLIVEC_RGBA(254, 206, 0, 255));
    } else if (!strcmp(country, "th")) {
        uint32_t red = OLIVEC_RGBA(237, 27, 36, 255);
        uint32_t blue = OLIVEC_RGBA(36, 29, 80, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 6, red);
        olivec_rect(oc, 0, HEIGHT - HEIGHT / 6, WIDTH, HEIGHT / 6, red);
        olivec_rect(oc, 0, 2 * HEIGHT / 6, WIDTH, 2 * HEIGHT / 6, OLIVEC_RGBA(36, 29, 80, 255));
    } else if (!strcmp(country, "fr")) {
        uint32_t red = OLIVEC_RGBA(237, 40, 57, 255);
        uint32_t blue = OLIVEC_RGBA(0, 36, 150, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, blue);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, white);
    } else if (!strcmp(country, "it")) {
        uint32_t red = OLIVEC_RGBA(207, 43, 54, 255);
        uint32_t green = OLIVEC_RGBA(0, 146, 71, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, green);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, white);
    } else if (!strcmp(country, "en")) {
        int lineheight = HEIGHT / 5;
        uint32_t red = OLIVEC_RGBA(206, 18, 35, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, 0, lineheight * 2, WIDTH, lineheight, red);
        olivec_rect(oc, WIDTH / 2 - lineheight / 2, 0, lineheight, HEIGHT, red);
    } else if (!strcmp(country, "co")) {
        uint32_t yellow = OLIVEC_RGBA(253, 209, 22, 255);
        uint32_t blue = OLIVEC_RGBA(1, 56, 147, 255);
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        olivec_fill(oc, OLIVEC_RGBA(253, 209, 22, 255));
        olivec_rect(oc, 0, 2 * HEIGHT / 4, WIDTH, HEIGHT / 4, blue);
        olivec_rect(oc, 0, 3 * HEIGHT / 4, WIDTH, HEIGHT / 4, red);
    } else if (!strcmp(country, "ua")) {
        uint32_t blue = OLIVEC_RGBA(1, 92, 187, 255);
        uint32_t yellow = OLIVEC_RGBA(254, 213, 0, 255);
        olivec_fill(oc, yellow);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 2, blue);
    } else if (!strcmp(country, "pl")) {
        uint32_t red = OLIVEC_RGBA(220, 19, 59, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 2, white);
    } else if (!strcmp(country, "sd")) {
        uint32_t red = OLIVEC_RGBA(210, 16, 51, 255);
        uint32_t green = OLIVEC_RGBA(0, 114, 42, 255);
        olivec_fill(oc, black);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
        olivec_triangle(oc, 0, 0, WIDTH / 3, HEIGHT / 2, 0, HEIGHT, green);
    } else if (!strcmp(country, "pe")) {
        uint32_t red = OLIVEC_RGBA(217, 16, 35, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, white);
    } else if (!strcmp(country, "ye")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        olivec_fill(oc, black);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
    } else if (!strcmp(country, "mg")) {
        uint32_t red = OLIVEC_RGBA(252, 62, 50, 255);
        uint32_t green = OLIVEC_RGBA(1, 126, 58, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, WIDTH / 3, 0, 2 * WIDTH / 3, HEIGHT / 2, red);
        olivec_rect(oc, WIDTH / 3, HEIGHT / 2, 2 * WIDTH / 3, HEIGHT / 2, green);
    } else if (!strcmp(country, "ci")) {
        uint32_t green = OLIVEC_RGBA(0, 158, 97, 255);
        uint32_t yellow = OLIVEC_RGBA(246, 127, 0, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, yellow);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, white);
    } else if (!strcmp(country, "ro")) {
        uint32_t blue = OLIVEC_RGBA(1, 43, 127, 255);
        uint32_t yellow = OLIVEC_RGBA(253, 209, 22, 255);
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, blue);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, yellow);
    } else if (!strcmp(country, "ne")) {
        uint32_t orange = OLIVEC_RGBA(224, 82, 6, 255);
        uint32_t green = OLIVEC_RGBA(12, 176, 43, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, orange);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
        olivec_circle(oc, WIDTH / 2, HEIGHT / 2, HEIGHT / 3 / 3, orange);
    } else if (!strcmp(country, "ml")) {
        uint32_t green = OLIVEC_RGBA(21, 181, 59, 255);
        uint32_t yellow = OLIVEC_RGBA(253, 209, 22, 255);
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, green);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, yellow);
    } else if (!strcmp(country, "nl")) {
        uint32_t red = OLIVEC_RGBA(174, 28, 39, 255);
        uint32_t blue = OLIVEC_RGBA(33, 70, 140, 255);
        olivec_fill(oc, blue);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
    } else if (!strcmp(country, "gn")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        uint32_t yellow = OLIVEC_RGBA(254, 209, 22, 255);
        uint32_t green = OLIVEC_RGBA(0, 148, 96, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, red);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, yellow);
    } else if (!strcmp(country, "td")) {
        uint32_t blue = OLIVEC_RGBA(0, 38, 100, 255);
        uint32_t yellow = OLIVEC_RGBA(254, 203, 0, 255);
        uint32_t red = OLIVEC_RGBA(198, 12, 49, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, blue);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, yellow);
    } else if (!strcmp(country, "be")) {
        uint32_t yellow = OLIVEC_RGBA(250, 224, 67, 255);
        uint32_t red = OLIVEC_RGBA(237, 40, 57, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH / 3, HEIGHT, black);
        olivec_rect(oc, WIDTH / 3, 0, WIDTH / 3, HEIGHT, yellow);
    } else if (!strcmp(country, "bo")) {
        uint32_t red = OLIVEC_RGBA(213, 43, 30, 255);
        uint32_t yellow = OLIVEC_RGBA(250, 227, 1, 255);
        uint32_t green = OLIVEC_RGBA(0, 120, 51, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, yellow);
    } else if (!strcmp(country, "bj")) {
        uint32_t green = OLIVEC_RGBA(1, 134, 81, 255);
        uint32_t yellow = OLIVEC_RGBA(253, 209, 22, 255);
        uint32_t red = OLIVEC_RGBA(232, 18, 46, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, WIDTH / 3, 0, 2 * WIDTH / 3, HEIGHT / 2, yellow);
        olivec_rect(oc, WIDTH / 3, HEIGHT / 2, 2 * 2 * WIDTH / 3, HEIGHT / 2, red);
    } else if (!strcmp(country, "cz")) {
        uint32_t blue = OLIVEC_RGBA(16, 69, 126, 255);
        uint32_t red = OLIVEC_RGBA(215, 20, 26, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 2, white);
        olivec_triangle(oc, 0, 0, WIDTH / 2, HEIGHT / 2, 0, HEIGHT, blue);
    } else if (!strcmp(country, "se")) {
        int lineheight = HEIGHT / 5;
        uint32_t blue = OLIVEC_RGBA(0, 82, 146, 255);
        uint32_t yellow = OLIVEC_RGBA(254, 203, 0, 255);
        olivec_fill(oc, blue);
        olivec_rect(oc, 0, lineheight * 2, WIDTH, lineheight, yellow);
        olivec_rect(oc, WIDTH / 10 * 3, 0, lineheight, HEIGHT, yellow);
    } else if (!strcmp(country, "hu")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        uint32_t green = OLIVEC_RGBA(0, 134, 71, 255);
        olivec_fill(oc, green);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
    } else if (!strcmp(country, "at")) {
        uint32_t red = OLIVEC_RGBA(236, 39, 56, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
    } else if (!strcmp(country, "ch")) {
        int col = WIDTH / 5;
        int row = HEIGHT / 5;
        uint32_t red = OLIVEC_RGBA(254, 0, 0, 255);
        olivec_fill(oc, white);
        olivec_rect(oc, 0, 0, col * 2, row * 2, red);
        olivec_rect(oc, 0, HEIGHT - row * 2, col * 2, row * 2, red);
        olivec_rect(oc, WIDTH - col * 2, 0, col * 2, row * 2, red);
        olivec_rect(oc, WIDTH - col * 2, HEIGHT - row * 2, col * 2, row * 2, red);
        olivec_rect(oc, col * 2, 0, col, row, red);
        olivec_rect(oc, 0, row * 2, col, row, red);
        olivec_rect(oc, col * 2, HEIGHT - row, col, row, red);
        olivec_rect(oc, WIDTH - col, row * 2, row, col, red);
    } else if (!strcmp(country, "laos")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        uint32_t blue = OLIVEC_RGBA(0, 39, 104, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, HEIGHT / 4, WIDTH, 2 * HEIGHT / 4, blue);
        olivec_circle(oc, WIDTH / 2, HEIGHT / 2, WIDTH / 5, white);
    } else if (!strcmp(country, "bg")) {
        uint32_t green = OLIVEC_RGBA(0, 151, 110, 255);
        uint32_t red = OLIVEC_RGBA(214, 37, 17, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, white);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, green);
    } else if (!strcmp(country, "sl")) {
        uint32_t green = OLIVEC_RGBA(31, 181, 58, 255);
        uint32_t blue = OLIVEC_RGBA(0, 114, 197, 255);
        olivec_fill(oc, blue);
        olivec_rect(oc, 0, 0, WIDTH, HEIGHT / 3, green);
        olivec_rect(oc, 0, HEIGHT / 3, WIDTH, HEIGHT / 3, white);
    } else if (!strcmp(country, "ae")) {
        uint32_t red = OLIVEC_RGBA(206, 17, 39, 255);
        uint32_t green = OLIVEC_RGBA(0, 158, 73, 255);
        olivec_fill(oc, red);
        olivec_rect(oc, WIDTH / 4, 0, 3 * WIDTH / 4, HEIGHT / 3, green);
        olivec_rect(oc, WIDTH / 4, HEIGHT / 3, 3 * WIDTH / 4, HEIGHT / 3, white);
        olivec_rect(oc, WIDTH / 4, 2 * HEIGHT / 3, 3 * WIDTH / 4, HEIGHT / 3, black);
        // TODO: denmark and after...
    } else {
        free((char*)file_path);
        fprintf(stderr, "Country not yet implemented!\n");
        return 1;
    }

    if (!stbi_write_png(file_path, WIDTH, HEIGHT, 4, pixels, sizeof(uint32_t) * WIDTH)) {
        fprintf(stderr, "ERROR: could not write %s\n", file_path);
        free((char*)file_path);
        return 1;
    }
    free((char*)file_path);
    return 0;
}
