# Modelagem de Software

> What is sofware engineering?

- Sofware engineering is an engineering discipline that is concerned with all aspects of software production
- Software engineers should adopt a systematic and organised approach to their work and use appropriate tools and techniques depending on the problem to be solved, the development constraints and the resource available.

> What is software process?

- A set of activities whose goal is the development or evolution of software
- Generic activities in tall software processes are:
  - Specification - what the system should do and its development constraints
  - Development - production of the software system
  - Validation
  - Evaluation

> What is software process model?

- A simplified representation of a software process, presented from a specific perspective
- Examples of process perspectives are
  - Workflow perspective - sequence of activities
  - Data-flow perspective - information flow
  - Role/action perspective - who does what
- Generic process models
  - Waterfall
  - Iterative development
  - Component-based software engineering

> What are software engineering methods?

- Structured approaches to software development which include system models, notations, rules, design advice and process guidance
- Models descriptions (MSW)
  - Descriptions of graphical models which should be produced
- Rules (MSW)
  - Constraints applied to system models
- Recommendations (MSW)
  - Advice on good design practice
- Process guidance (ESW)
  - What activities to follow

## Diagramas UML (Unified Modeling Language)

![umlDiagram](images/umlDiagram.png)

### Importância relativa dos diagramas

![diagramUses](images/diagramUses.png)

### Requisitos de Software

![softwareReqs](images/softwareReqs.png)

### Documento de Requisito de Software

- O documento de requisitos de software é a declaração final do que é demandado dos desenvolvedores do sistema
- Deve incluir ambas, uma definição de requisitos do usuário e a uma especificação de requisitos do sistema
- NÃO é um documento de projeto. Na medida do possível, deve definir O QUE o sistema deve fazer ao ínves de COMO deve fazê-lo

### Documento de Requisitos

![docReq0](images/docReq0.png)
![docReq1](images/docReq1.png)

### Possibilidades de Notações

![anotPossibilities0](images/anotPossibilities0.png)

### Casos de Usos

- Capturam requisitos funcionais
  - E requisitos não-funcionais
- Descreve interação entre "usuários" e o sistema
- Provêem uma narrativa de como o sistema é usado

### Como criar um diagrama de caso de uso?

- Roteiros:
  1. The customer browses the catalog and adds desired items to the shopping basket
  2. When the cusomter wishes to pay, the customer describes the shipping and credit card information on the credit card information and confirms the sale
  3. The system checks the authorization on the credit card and confirms the sale both immediately and with a follow-up e-mail
- E se:
  1. A autorização de crédito falhar?
  2. Se o cliente já tem informações de envio e de cartão já cadastrados

### O que tem de comum nos diversos roteiros?

- Comprar produtos!!!

> Um caso de uso é um conjunto de roteiros ligados conjutamente por um objetivo comum do usuário

### Atores

- Atores são os papéis representados por elementos que interagem em um sistema
- Um ator pode interagir através de vários casos de usos
- Um caso de uso pode ser executado por vários atores
- Ator é algo externo ao sistema
- Um ator pode ser um sistema externo

### Descrição de um caso de uso

![useCaseDescription](images/useCaseDescription.png)

### Outra possíveis informações

- A pre-condition describes what the system should ensure before the system allows the use case to begin
  - This is useful for telling the programmers what coditions they don't have to check for in their code
- A guarantee describes what the system will ensure at the end of the use case
  - Success guarantees hold after a successful scenario; minimal guarantees hold after any scenario
- A trigger specifices the event that gets the use case started

### Outro exemplo: Seja um CMS (Blog, Wiki, ...)

- Requisito 1: The content management system shall allow an administrator to create a new blog account, provided the personal details of the new blogger are verified using the author credentials
- Requisito 2: The content management system shall allow an administrator to create a new personal Wiki, provided the personal of the applying author are verified using the Author Credentials

### Seja um caso de uso: Create a New Blog Account

![newBlogAccUseCase](images/newBlogAccUseCase.png)

### O diagrama de casos de usos

![useCaseDiagram](images/useCaseDiagram.png)

### Níveis de abstração para os casos de usos

- Usual
  - System use cases
  - Business Use Cases

### Extends

- Citando Martin Fowler:
  - "Evite usar!"
- As pessoas tendem a confundir a semântica
  
![extendsNotation](images/extendsNotation.png)

### Features and Use Cases

- Features (User stories in XP)
  - Propósito: agrupar requisitos que serão entregues em determinados pontos de um projeto iterativo
- A feature may be:
  - a whole use case
  - a scenario (roteiro) in a use case
  - a step in a use case
  - or some variant behavior, that doesn't show up in a use case narrative
- Usually, features are more fine grained than use cases

### Diagrama de Visão Geral dos Casos de Uso

- The CMS's context as shown on a Use Case Overview diagram

![useCaseContext](images/useCaseContext.png)

### Dicas (Fowler)

- Use cases represent an external view of the system.
  - As such, don't expect any correlations between use cases and the classes inside the system
- The more I see of use cases, the less valuable the use case diagram seems to be
  - With use cases, concentrate your enery on their text rather than on the diagram
  - Despite the fact that the UML has nothing to say about the use case text, it is the text that contains all the value in the technique
- A big danger os use cases is the that people make them too complicated and get stuck
  - Usually, you'll get less hurt by doing too litte than by doing too much. A couple of pages per use case is just fine for most cases
  - If you have too little, at least you'll have a short, readable document that's a starting point for questions
  - If you have too much, hardly anyone will read and understand it

### Vantagens

- One of the important strengths of a use case diagram is it's ability to model of the actor (role, as per Fowler, 2003)
  - The actor demostrates clearly to the user
    - who is involved in specifying requirements
    - where he existis in the context of the software system
  - The actor also play a crucial role in enabling the business analyst to undestand and document the use's requirements
  - The actor helps users to express their requirements in greater details because the users see themselves represented on the use case
- Use case diagrams facilitate discussions among various parties involved in requirements modeling
  - The business analysts
  - users
  - designers
- Use cases and use case diagrams help to organize the requirements
  - The notation for a use case represents a cohesive set of interactions between the user and the system
  - By simply referring to a use case, a complex set of interactions can be accessed easily, thereby simplifying the discussions
- Use cases document complete functional requirements
  - no separate functional requirements document is needed
  - although additional operational and interface requirements or additional details may be placed in a separate document
- Relationships of include and extend between use cases provide means to extend and reuse requirements
  - Actors can also be generalized in use case diagrams
  - The ability to show pictorially an abstract actor that deals with the most common users of the system is a major strength of use case diagrams
- Use cases facilitate tracing of requirements
  - By providing well-organized documentation of the requirements, a use case creates a trace for a particular requirement throughout the system
- Document the context of the system
  - by creating a system boundary
- Use case diagrams form the basis for creation and documentation of use cases

### Desvantagens

- Use cases themselves have no formal documentation standard
  - this creates ans opportunity for modelers and project managers to develop their own standards, as well as their own interpretation of what needs to be documented
- Use cases are not intrinsically object-oriented
  - They are not an ideal mechanism to model design-level constructs in the solution space (where object orientation plays an important role)
- The meaning behind the association or communication relationship between the actor and the corresponding use case is not clear
  - If the actor initiating the use case is a human actor, then the convention is to show an arrowhead pointing to the use case
  - However, if the use case represents a series of interactions between the actor and the system, the arrowhead on the association between the actor and the use case does not make sense
- Use case-to-use case relationships are also not precise, leading to confusion
  - generalization/extend between use cases will be imprecise, as there are no well defined attributes and operations in a use case
- While use cases themselves document business processes, use case diagrams do not exhibit any sequential flow and don ot depict any dependency
  - Thus use case diagrams are not an ideal mechanism to show the flow between different entities within the system
- Use cases descriptions and use case diagrams do not have a granularity standard

## Processos

### Melhores Práticas

- Desenvolver software iterativamente
- Gerenciar requisitos
- Usar arquiteturas baseadas em componentes
- Modelar o software visualmente
- Verificar continuamente a qualidade do software
- Controlar as alterações no software

### RUP

- Um processo de engenharia de software
- Um framework para outros processos
- Utiliza as melhores práticas de desenvolvimento de software

### RUP x Casos de Uso

- RUP é dirigido por caso de uso (use-case driven)
- Casos de uso dirigem inumerosas atividades
  - Criação e validação dos modelos de projeto
  - Definição dos casos de teste no modelo de teste
  - Planejamento de iterações
  - Criação do manual do usuário

### RUP x Arquitetura

- RUP é centrado na arquitetura
- A arquitetura é central em relação aos esforços
  - Os requisitos são analisados para montar uma arquitetura
  - A arquitetura orienta a implementação e mudanças

![arcEx](images/arcEx.png)

---

![RUPVision](images/RUPVision.png)

---

![rupProc](images/rupProc.png)

---

![rupPhases](images/rupPhases.png)

### Desenvolvimento Iterativo

- Análise do Risco

![iterativeWaterfallDevelop](images/iterativeWaterfallDevelop.png)

---

![rupCycleIterative](images/rupCycleIterative.png)

---

- Vantagens
  - Os riscos

### Gerência de Requisitos

### Arquitetura Baseada em Componentes

### Gerência de Mudanças

### Conceitos Chave

![keyConceptsRup](images/keyConceptsRup.png)

### Elementos do RUP

### Disciplinas

- Workflow de atividades correlatas
- Alguns elementos, como risco e testes, são introduzidos

---

![rupDiagram](images/rupDiagram.png)