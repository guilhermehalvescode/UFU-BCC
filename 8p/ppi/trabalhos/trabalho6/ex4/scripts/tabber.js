function tabChange(e) {
    //remove active (apenas acha os elementos que estão ativos)
    document.querySelector(".tabActive").className = ""
    document.querySelector(".active").className = ""

    //adicionar seção ativa com base no target
    const targetName = e.target.dataset["tabref"]
    document.querySelector('[data-tabref="' + targetName + '"]').className = "tabActive"
    document.querySelector('[data-tab="' + targetName + '"]').className = "active"

}


window.addEventListener("DOMContentLoaded", () => {
    // adiciona os listeners dos botões para ativar as seções da página
    const tabButtons = document.querySelectorAll("nav button")

    for(let btn of tabButtons)
        btn.addEventListener("click", e => tabChange(e))
    
})


