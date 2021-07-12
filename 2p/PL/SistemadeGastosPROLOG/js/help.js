const perguntas = document.querySelectorAll(".pergunta_container");

perguntas.forEach(pergunta => {
    pergunta.addEventListener("click", (e) => {
        const resposta = pergunta.querySelector(".resposta_container");
        const icon = pergunta.querySelector("i");

        resposta.classList.toggle("resposta_active");
        icon.classList.toggle("icon_active");
    })
})