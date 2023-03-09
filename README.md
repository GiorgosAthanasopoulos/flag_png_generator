# flag_png_generator
Png generator for all of the world's countries' flags. (Work in Progress)

## Dependencies
<ul>
<li><a target="_blank" rel="noreferrer" href="https://www.github.com/tsoding/olive.c">Tsoding's olive.c</a></li>(to generate the image)
<li><a target="_blank" rel="noreferrer" href="https://raw.githubusercontent.com/nothings/stb/master/stb_image_write.h">std_image_write.h</a></li>(to write the image on the filesystem)
<li><a target="_blank" rel="noreferrer" href="https://github.com/derf/feh">Feh</a></li>to auto-preview the images(You can change this in the `run` bash script file).
</ul>

## Usage
In your terminal run:
<ul>
<li>`chmod +x ./run`</li>
<li>Then use with: `./run {country_abbreviation} {width} {height}`</li>
</ul>
All of the flags will be saved in the flags directory(by default).

## Example
<ul>
<li>Greece: `./run gr 1280 720`</li>
<li>Colombia: `./run co 900 600`</li>
</ul>
