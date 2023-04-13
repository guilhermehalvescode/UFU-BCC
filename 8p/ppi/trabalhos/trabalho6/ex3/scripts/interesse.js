function addInteresse() {
    
    const ol = document.querySelector("ol")
    const input = document.querySelector("input")
    
    // cria os elementos do li
    let novoLi = document.createElement("li")
    let novoSpan = document.createElement("span")
    let novoButton = document.createElement("button")

    // coloca no novo span o texto do input
    novoSpan.textContent = input.value
    novoButton.textContent = 'X'


    //adiciona no botão de remover para remover o li (pai do botão)
    novoButton.addEventListener("click", e => e.target.parentNode.remove())

    // adiciona no li o span e o botão
    novoLi.appendChild(novoSpan)
    novoLi.appendChild(novoButton)

    // adiciona na lista ordenada o elemento do novo li
    ol.appendChild(novoLi)

    input.value = ''
}

window.addEventListener("DOMContentLoaded", () => {
    // pega o input dos interesses e adicionar o listener de quando apertar enter
    const input = document.querySelector("input")
    input.addEventListener("keyup", e => {
        if(e.key === "Enter")
            addInteresse()
    })
})

