//shader vertex
#version 430 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec4 c;


out vec2 TexCoord;
out vec4 color;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
	TexCoord = aTexCoord;
    color = c;
}


//shader fragment
#version 430 core
out vec4 FragColor;
in vec2 TexCoord;
in vec4 color;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, TexCoord) * vec4(color);
}
