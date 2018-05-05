#version 130

uniform sampler2D texture;
uniform float u_time;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    gl_FragColor = vec4(pixel.xyz, sin(u_time));
}
