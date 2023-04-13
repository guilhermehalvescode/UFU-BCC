function tabChange(e) {
    //remove active (apenas acha os elementos que estão ativos)
    
    document.querySelector(".active").classList.remove("active")

    document.querySelector(".activeDiv").classList.remove("activeDiv")

    //adicionar seção ativa com base no target
    const targetName = e.target.dataset["tabref"]
    document.querySelector('[data-tabref="' + targetName + '"]').classList.add("active")
    document.querySelector('[data-tab="' + targetName + '"]').classList.add("activeDiv")

}


window.addEventListener("DOMContentLoaded", () => {
    // adiciona os listeners dos botões para ativar as seções da página
    const links = document.querySelectorAll("li a[data-tabref]")
    
    for(let lk of links)
        lk.addEventListener("click", e => tabChange(e))
    
})


