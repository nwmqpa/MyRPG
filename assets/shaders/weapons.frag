#version 130

uniform sampler2D texture;
uniform vec4 dmg;
uniform vec4 spd;
uniform vec4 split;
uniform vec4 dmg_repl;
uniform vec4 spd_repl;
uniform vec4 split_repl;

void main()
{
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	vec4 eps = vec4(0.00009, 0.00009, 0.00009, 0.00009);

	if(all(greaterThanEqual(pixel, dmg - eps)) && all(lessThanEqual(pixel, dmg + eps)))
		pixel = dmg_repl;
	if(all(greaterThanEqual(pixel, spd - eps)) && all(lessThanEqual(pixel, spd + eps)))
		pixel = spd_repl;
	if(all(greaterThanEqual(pixel, split - eps)) && all(lessThanEqual(pixel, split + eps)))
		pixel = split_repl;
	gl_FragColor = pixel;
}