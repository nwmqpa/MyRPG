#version 130

uniform float u_time;

void main()
{
    vec3 violet = vec3(1.0, 0.1, 0.8);
    vec3 yellow = vec3(1.0, 1.0, 0);
    vec3 color = mix(violet, yellow, abs(sin(u_time)));

    gl_FragColor = vec4(color, 1.0);
}
