*** Settings ***
Library  SeleniumLibrary

Test Setup  ouvrir Prestashop
Test Teardown  fermer Prestashop

*** Test Cases ***
chercher mug
    # Title Should Be  www.qualifiez.fr
    Rechercher  mug
    # Verifier texte  ${number of products}  Il y a 5 produits.
    # Verifier liste  ${liste d'articles}  mug

tester le nombre de produits d'une catégorie
    [Template]  Rechercher et verifier
    mug  Il y a 5 produits.
    T-shirt  Il y a 1 produit.

vérifier que "homme" n'est visible qu'au survol de "vêtements" à la souris
    #Selon Selenium, le curseur est placé par défaut dans le coin haut-gauche de la fenêtre
    #Donc il n'est pas accidentellement placé sur vêtements au départ
    Ne doit pas être visible  ${menu homme}
    Survoler avec la souris  ${vetements}
    Doit être visible  ${menu homme}


# test firefox
#     Open Browser  http://www.qualifiez.fr/monPrestashop2/prestashop   ff  ff_profile_dir=/home/quentin/snap/firefox/common/.mozilla/firefox/jbw57s7t.default
#     Close Browser

*** Variables ***

${Prestashop}  http://www.qualifiez.fr/monPrestashop2/prestashop/index.php
${Search}  xpath=//*[@id="search_widget"]/form/input[2]
${Search2}  xpath=/html/body/main/header/div[2]/div/div[1]/div[2]/div[2]/form/input[2]
${number of products}  //*[@id="js-product-list-top"]/div[1]/p
${liste d'articles}  //*[@id="js-product-list"]/div[1]/div/article/div/div[2]/h2/a
${vetements}  //*[@id="category-3"]/a
${menu homme}  //*[@id="category-4"]/a
${Hooper}  https://www.hooper.fr/  

*** Keywords ***

ouvrir Prestashop
    Open Browser  ${Prestashop}   gc
    Maximize Browser Window
    Title Should Be  monPrestashop

fermer Prestashop
    Close Browser

ouvrir Hooper.fr
    Open Browser  ${Hooper}   gc
    Title Should Be  hooper
    Maximize Browser Window


Rechercher
    [Arguments]  ${item}
    Input Text   ${Search}  ${item}
    Press Keys  ${Search}  RETURN

Verifier texte
    [Arguments]  ${message}  ${item}
    Element Text Should Be  locator=${message}  expected=${item}

Verifier liste
    [Arguments]  ${liste}  ${item}
    @{liste_elt}  Get WebElements  locator=${liste}
    FOR  ${elt}  IN  @{liste_elt}
        Element Should Contain  ${elt}  ${item}  ignore_case=True
    END

Rechercher et verifier
    [Arguments]  ${item}  ${msg}
    Rechercher  ${item}
    Verifier texte  ${number of products}  ${msg}

Survoler avec la souris
    [Arguments]  ${item}
    Mouse Over  ${item}

Doit être visible
    [Arguments]  ${item}
    Element Should Be Visible  ${item}

Ne doit pas être visible
    [Arguments]  ${item}
    Element Should Not Be Visible  ${item}