function validaForm(e) {
    let form = e.target

    let formValido = true

    // seleciona paragrafo do aviso de erro
    const erroNome = form.nome.nextElementSibling
    const erroEmail = form.email.nextElementSibling
    const erroMensagem = form.mensagem.nextElementSibling

    // limpa ele
    erroNome.textContent = ''
    erroEmail.textContent = ''
    erroMensagem.textContent = ''


    // se estiver vazio, acusa erro no paragrafo de aviso do erro
    if (form.nome.value === "") {
        erroNome.textContent = "O nome deve ser preenchido!"
        formValido = false
    }
    
    // se estiver vazio, acusa erro no paragrafo de aviso do erro
    if (form.email.value === "") {
        erroEmail.textContent = "O email deve ser preenchido!"
        formValido = false
    }
    
    // se estiver vazio, acusa erro no paragrafo de aviso do erro
    if (form.mensagem.value === "") {
        erroMensagem.textContent = "A mensagem deve ser preenchida!"
        formValido = false
    }

    // se estiver invalido, previne o envio do form
    if (!formValido)
        e.preventDefault()
}



window.addEventListener("DOMContentLoaded", () => {
    
    // atribui função personalizada para ser chamada antes do envio do formulario
    document.forms.registraContato.onsubmit = validaForm
})