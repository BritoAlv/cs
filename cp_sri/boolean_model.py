import spacy
import ir_datasets
from sympy import Basic, sympify, to_dnf, Not, And, Or, Symbol

nlp = spacy.load("en_core_web_sm")

def tokenize(
    text,
    special_tokens=["and", "or", "not", "(", ")"],
    tag_list=["ADJ", "ADV", "NOUN", "VERB", "PROPN"],
):
    doc = nlp(text)
    tokens = []
    for tk in doc:
        if (tk.text.isalpha() and (tk.pos_ in tag_list)) or tk.lemma_ in special_tokens:
            tokens.append(tk.lemma_)
    return tokens

def build_inverted_index(data):
    dictt = {}
    for doc in data:
        for token in doc[1]:
            if token not in dictt:
                dictt[token] = []
            dictt[token].append(doc[0])
    return dictt

def replace(pos, arr, matches=[("and", "&"), ("or", "|"), ("not", "~")]):
    for match in matches:
        if arr[pos] == match[0]:
            arr[pos] = match[1]

def query_to_dnf(query):
    queryTokens = tokenize(query)
    for i in range(0, len(queryTokens)):
        replace(i, queryTokens)

    result = ""
    for tk in queryTokens:
        result += tk
        result += " "

    # blows up with queries like:
    # to be or not to be
    # exp x
    return to_dnf(sympify(result))


def clauses(expr, op):
    if not isinstance(expr, op):
        return [expr]
    return expr.args

def WorkAnd(clauseAnd, doc, inv_index_ds):
    result = True
    for clause in clauses(clauseAnd, And):
        part = ""
        if isinstance(clause, Not):
            part = str(clause.args[0])     
        else:
            part = str(clause)
        result = result and ( isinstance(clause, Not) ^ (part in inv_index_ds and doc[0] in inv_index_ds[part]))
    return result

def WorkOr(clauseOr, doc, inv_index_ds):
    result = False
    for clause in clauses(clauseOr, Or):
        result = result or WorkAnd(clause, doc, inv_index_ds)
    return result

def get_matching_docs(query_dnf, docs):
    inv_index_ds = build_inverted_index(tokenized_docs)
    result = [WorkOr(query_dnf, doc, inv_index_ds) for doc in docs]
    return result

try:
    dataset = ir_datasets.load("cranfield")
    docs = dataset.docs_iter()
    tokenized_docs = []
    for doc in docs:
        if len(tokenized_docs) >= 10:
            break
        tokenized_docs.append((doc[1], tokenize(doc[2])))
    query = "experimental"
    model_result = get_matching_docs(query_to_dnf(query), tokenized_docs)
    for i in range(0, len(model_result)):
        if model_result[i]:
            print(tokenized_docs[i][0])
except Exception as e:
    print(e)
    pass