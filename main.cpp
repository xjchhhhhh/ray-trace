#include <fstream>
#include <iostream>

#include "math/vec3.h"

using color = vec3;

void write_color(std::ofstream &out, const color &pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

int main() {
    int image_width = 500;
    int image_height = 500;
    // Render
    std::ofstream outfile;
    outfile.open("picture.ppm", std::ios::out);

    outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            // std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            write_color(outfile, {r, b, g});
        }
    }

    std::clog << "\rDone.                 \n";
    return 0;
}
