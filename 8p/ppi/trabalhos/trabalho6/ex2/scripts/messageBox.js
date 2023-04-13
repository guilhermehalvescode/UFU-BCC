function showMessage() {
    // seleciona o elemento do modal
    const mb = document.querySelector("#messageBox")

    // e altera a visibilidade do mesmo
    mb.style.visibility = 'visible';
}

window.addEventListener("DOMContentLoaded", () => {
    
    // pega referencia na arvore dom do botão para abrir o modal
    const btn = document.querySelector("#showMessageBox")
    
    // adiciona um listener no mesmo
    btn.addEventListener("click", () => {
        // o listener ira chamar a abertura do modal
        showMessage()
    });
    
    
    // seleciona o botão de dentro do modal, usado para fecha-lo
    const btnShowMessageBox = document.querySelector("#messageBox button")

    // adiciona o listener no mesmo para fechar
    btnShowMessageBox.addEventListener("click", () => {
        
        // seleciona a messagebox (modal) e "fecha" o modal, mudando sua visibilidade para hidden
        const mb = document.querySelector("#messageBox")
        mb.style.visibility = 'hidden'
    })

})




