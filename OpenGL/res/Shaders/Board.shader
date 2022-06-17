#shader vertex
#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec4 Colour;

out vec4 v_Colour;

uniform vec2 u_screensize;

void main()
{
	gl_Position = vec4(position, 1.0f, 1.0f);
	v_Colour = Colour;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;
in vec4 v_Colour;


float near = 0.0001;
float far = 1000.0;

uniform vec4 u_Color;
uniform vec3 u_Pos;


void main()
{
	color = v_Colour;
}