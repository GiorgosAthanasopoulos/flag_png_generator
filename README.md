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
<li>Greece(default 900x600): `./run gr`</li>
<li>Greece(1280x720): `./run gr 1280 720`</li>
<li>Colombia: `./run co 900 600`</li>
</ul>

## Countries
Here is a list of the implemented country flags:
<ul>
<li>COUNTRY: ABBREVIATION</li>
<li>Greece: gr</li>
<li>Japan: jp</li>
<li>Indonesia: id</li>
<li>Nigeria: ng</li>
<li>Bangladesh: bd</li>
<li>Russia: ru</li>
<li>Germany: de</li>
<li>Thailand: th</li>
<li>France: fr</li>
<li>Italy: it</li>
<li>England: en</li>
<li>Colombia: co</li>
<li>Ukraine: ua</li>
<li>Poland: pl</li>
<li>Sudan: sd</li>
<li>Peru: pe</li>
<li>Yemen: ye</li>
<li>Madagascar: mg</li>
<li>Côte d'Ivoire: ci</li>
<li>Romania: ro</li>
<li>Niger: ne</li>
<li>Mali: ml</li>
<li>Netherlands: nl</li>
<li>Guinea: gn</li>
<li>Chad: td</li>
<li>Belgium: be</li>
<li>Bolivia: bo</li>
<li>Benin: bj</li>
<li>Czechia: cz</li>
<li>Sweden: se</li>
<li>Hungary: hu</li>
<li>Austria: at</li>
<li>Switzerland: ch</li>
<li>Laos: laos</li>
<li>Bulgaria: bg</li>
<li>Sierra Leone: sl</li>
<li>United Arab Emirates: ae</li>
<li>Denmark: dk</li>
<li>Finland: fl</li>
<li>Norway: no</li>
<li>Scotland: sco</li>
<li>Ireland: ie</li>
<li>Palau: pw</li>
<li>Monaco: mc</li>
<li>Luxembourg: lu</li>
<li>Estonia: ee</li>
<li>Mauritius: mu</li>
<li>Gabon: ga</li>
<li>Latvia: lv</li>
<li>Lithuania: lt</li>
<li>Armenia: am</li>
</ul>
