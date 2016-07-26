#version 430 core
 
void main(void)
{
   const vec4 vertices[6] = vec4[6](vec4( 0.25, -0.25, 0.5, 1.0),
                                    vec4(-0.25, -0.25, 0.5, 1.0),
                                    vec4( 0.25,  0.25, 0.5, 1.0),

									vec4( 0.45, -0.45, 0.5, 1.0),
                                    vec4(-0.65, -0.75, 0.5, 1.0),
                                    vec4( 0.65,  0.25, 0.5, 1.0));
   gl_Position = vertices[gl_VertexID];
}
