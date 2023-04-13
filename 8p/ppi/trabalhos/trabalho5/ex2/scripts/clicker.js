window.onload = () => {
    const h1DomRef = document.querySelector("h1");

    h1DomRef.addEventListener("click", e =>
        e.target.textContent = "Ciclano de Tal"
    )

    const h2Refs = document.querySelectorAll("h2");
    h2Refs.forEach(e =>
        e.addEventListener("click", () =>
            e.textContent = "Obrigado"
        )
    )
}


