#!/bin/sh

mvn archetype:generate \
    -DgroupId=com.anylonen.example \
    -DartifactId=hello-world \
    -DarchetypeArtifactId=maven-archetype-quickstart \
    -DinteractiveMode=false
