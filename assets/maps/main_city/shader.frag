#version 130

uniform sampler2D texture;
uniform float u_time;

float impulse(float k, float x)
{
	float h = k * x;
	return h * exp(1.0 - h);
}

void main()
{
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

	gl_FragColor = vec4(
		pixel.xyz,
		pixel.a * mod((impulse(1., sin(u_time * 3))), 1.)
	);
}
