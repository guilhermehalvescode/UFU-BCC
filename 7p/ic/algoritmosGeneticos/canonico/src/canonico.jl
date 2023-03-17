module canonico

using Random: bitrand, rand

const Cromossomo = BitVector
const Cromossomos = Vector{Cromossomo}

mutable struct Individuo
    cromossomo::Cromossomo
    aptidao::Float64

    function Individuo(numgenes::Int64, apt=-Inf)
        new(bitrand(numgenes), apt)
    end

    Individuo(c::Cromossomo, apt=-Inf) = new(c, apt)
end




end # module canonico
