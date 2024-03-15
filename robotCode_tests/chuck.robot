*** Settings ***

Library  RequestsLibrary
Library  Collections
Suite Setup   Create Session  chuck  ${endPoint}

*** Test Cases ***

hello world
  Log To Console  Hello World!

toto
    afficher  toto
    Should Be Equal  Bonjour  toto

afficher une blague
    ${blague}  récupérer une blague  
    afficher  ${blague}
    contient chuck  ${blague}
    # Log To Console  ${reponse.content}

afficher blague de chaque categorie
    @{categories}  récupérer categories
    FOR  ${categ}  IN  ${categories}
        ${blague}  récupérer une blague d'une categorie  ${categ}
        afficher  ${blague}
    END
    

*** Variables ***

${motAVerifier}  Chuck  
${endPoint}  https://api.chucknorris.io/
${randomJoke}  /jokes/random
${categoJoke}  /jokes/random?category=
${categories}  /jokes/categories


*** Keywords ***

afficher
    [Arguments]    ${var}
    Log To Console  ${var}
    RETURN  plouf

récupérer une blague
    ${reponse}  GET On Session  chuck  ${randomJoke}  expected_status=200
    RETURN  ${reponse.json()}[value]

récupérer une blague d'une categorie
    [Arguments]    ${var}
    ${reponse}  GET On Session  chuck  ${categoJoke}{${var}}  expected_status=200
    RETURN  ${reponse.json()}[value]



récupérer categories
    ${reponse}  GET On Session  chuck  ${categories}  expected_status=200
    ${json} =    Convert To Dictionary    ${reponse.json()}
    ${list} =    Get Dictionary Keys    ${json}
    RETURN  ${reponse}


contient chuck
    [Arguments]  ${var}
    Should Contain  ${var}  ${motAVerifier}  