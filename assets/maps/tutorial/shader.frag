#version 130

uniform sampler2D texture;
uniform float u_time;

float pcurve( float x, float a, float b ){
    float k = pow(a+b,a+b) / (pow(a,a)*pow(b,b));
    return k * pow( x, a ) * pow( 1.0-x, b );
}

void main()
{
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	float alpha = sin(u_time) * cos(u_time);

	gl_FragColor = vec4(
		pixel.xyz,
		pcurve(0.3, 1.0, alpha)
	);
}
