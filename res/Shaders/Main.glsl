#Shader vertex
#version 440
 
layout(location = 0) in vec4 positions;
layout(location = 1) in vec2 tex_pos;
layout(location = 2) in float tex_type;

uniform mat4 u_proj;
out vec2 tex_coord;
out float tex_id;

void main(){
        gl_Position = u_proj * positions;
        tex_coord = tex_pos;
        tex_id = tex_type;
}

#Shader fragment
#version 440

out vec4 frag_color;

in vec2 tex_coord;
in float tex_id;

uniform sampler2D textures[2];

void main(){
    if(tex_id >= 1.0)
        gl_FragColor  = texture(textures[1], tex_coord);
    else
        gl_FragColor  = texture(textures[0], tex_coord);


}