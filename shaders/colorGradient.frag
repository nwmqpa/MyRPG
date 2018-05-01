#version 130

void main()
{
	gl_FragColor = vec4(vec3(gl_TexCoord[0].x), 1.0);
}
