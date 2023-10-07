#pragma once

int main(){
    auto App = CG::createApplication();
    App->run();
    delete App;
    
    return 0;
}